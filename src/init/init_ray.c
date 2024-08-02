/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:23:37 by akamite           #+#    #+#             */
/*   Updated: 2024/08/02 19:07:48 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * データをセットする
 */
void	init_ray(t_ray *ray, t_game *game, int x)
{
	(void)x;
	initialize_ray(ray);
	ray->map_x = game->player.map_x;
}

/**
 * 初期化
 */
void	initialize_ray(t_ray *ray)
{
	ray->map_x = 0;
	ray->map_y = 0;
	ray->dist_to_wall = 0.0;
}
