/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:23:37 by akamite           #+#    #+#             */
/*   Updated: 2024/08/03 02:01:26 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * データをセットする
 */
void	init_ray(t_ray *ray, t_player *player, int x)
{
	initialize_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->vec_dir_x = player->vec_dir_x + player->vec_plane_x * ray->camera_x;
	ray->vec_dir_y = player->vec_dir_y + player->vec_plane_y * ray->camera_x;
	ray->map_x = (int)player->map_x;
	ray->map_y = (int)player->map_y;
	ray->deltadist_x = fabs(1 / ray->vec_dir_x);
	ray->deltadist_y = fabs(1 / ray->vec_dir_y);
	put_ray(ray);
}

/**
 * 初期化
 */
void	initialize_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->dist_to_wall = 0.0;
}
