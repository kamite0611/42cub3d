/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:54 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 23:21:48 by akamite          ###   ########.fr       */
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
static void	calculate_wall(t_ray *ray, t_game *game, t_player *player)
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
	if (ray->side == 0)
		ray->wall_x = player->map_y + ray->wall_dist * ray->vec_dir_y;
	else
		ray->wall_x = player->map_x + ray->wall_dist * ray->vec_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/**
 * レイを使用して縦軸のテクスチャを貼る
 */
static void	set_ray_pixels(t_game *game, t_ray *ray, int x)
{
	t_tex_ray	tex_ray;
	int			y;
	int			**wall_tex;

	y = -1;
	wall_tex = get_wall_texture(game, ray);
	init_tex_ray(game, ray, &tex_ray);
	while (++y < game->win_height)
	{
		if (y < ray->wall_start_y)
			set_ceiling_texture(game, ray, y, x);
		else if (y > ray->wall_end_y)
			set_floor_texture(game, ray, y, x);
		else
			game->view_pixels[y][x] = get_wall_color(game, wall_tex, &tex_ray);
	}
}

/**
 * DDAアルゴリズム
 * 壁への距離を取得する
 * ray.sidedist_yx	壁への距離
 * ray.side			x,y軸どちらの壁にぶつかったか side=0の場合x軸の壁
 */
static void	run_dda(t_game *game, t_ray *ray)
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
	while (x < game->win_width)
	{
		init_ray(&ray, &game->player, x);
		run_dda(game, &ray);
		calculate_wall(&ray, game, &game->player);
		// put_ray(&ray);
		set_ray_pixels(game, &ray, x);
		x++;
	}
}
