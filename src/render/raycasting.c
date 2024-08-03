/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:54 by akamite           #+#    #+#             */
/*   Updated: 2024/08/03 23:48:37 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * 壁の高さを計算
 */
static void	calculate_wall_height(t_ray *ray, t_game *game, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->wall_height = (int)(game->win_height / ray->wall_dist);
	ray->draw_start = -(ray->wall_height) / 2 + game->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->wall_height / 2 + game->win_height / 2;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->map_y + ray->wall_dist * ray->vec_dir_y;
	else
		ray->wall_x = player->map_x + ray->wall_dist * ray->vec_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	set_ray_pixels(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		game->view_pixels[y][x] = 100000;
		y++;
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
		calculate_wall_height(&ray, game, &game->player);
		set_ray_pixels(game, &ray, x);
		put_ray(&ray);
		x++;
	}
}
