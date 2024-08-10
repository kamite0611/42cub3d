/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:54 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 15:44:52 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 壁周りのデータを計算
 * wall_dist 壁までの距離
 * wall_height 壁の高さ
 * wall_start_y 壁を描画開始する座標
 * wall_end_y 壁を描画終了する座標
 */
static void	calculate_wall(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->wall_height = (int)(game->win_height / ray->wall_dist);
	ray->wall_start_y = -(ray->wall_height) / 2 + game->win_height / 2;
	if (ray->wall_start_y < 0)
		ray->wall_start_y = 0;
	ray->wall_end_y = ray->wall_height / 2 + game->win_height / 2;
	if (ray->wall_end_y >= game->win_height)
		ray->wall_end_y = game->win_height - 1;
}

static int	get_wall_color(t_game *game, t_ray *ray)
{
	(void)game;
	if (ray->side == 1)
		return (ray->vec_dir_y < 0 ? 100000 : 200000);
	else
		return (ray->vec_dir_x < 0 ? 600000 : 700000);
}

// wall_color
void	set_ray_pixels(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	wall_color;

	y = -1;
	wall_color = get_wall_color(game, ray);
	while (++y < game->win_height)
	{
		if (y < ray->wall_start_y)
			set_ceiling_texture(game, ray, y, x);
		else if (y > ray->wall_end_y)
			set_floor_texture(game, ray, y, x);
		else
			game->view_pixels[y][x] = wall_color;
	}
}

void	run_dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_hit_wall(game, ray))
			break ;
	}
}

/**
 * 光線を画面の横幅分出す
 */
void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < game->win_width)
	{
		init_ray(&ray, &game->player, x);
		run_dda(game, &ray);
		calculate_wall(&ray, game);
		set_ray_pixels(game, &ray, x);
		x++;
	}
}
