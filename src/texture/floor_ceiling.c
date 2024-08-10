/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:39:51 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 15:45:14 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 天井のテクスチャを貼る
 */
void	set_ceiling_texture(t_game *game, t_ray *ray, int y, int x)
{
	int	color;

	if (y < ray->wall_start_y)
	{
		color = game->mapinfo.ceiling_rgb[0] * 256 * 256
			+ game->mapinfo.ceiling_rgb[1] * 256 + game->mapinfo.ceiling_rgb[2];
		game->view_pixels[y][x] = color;
	}
	else
		free_exit(game, err_msg("can't set ceiling texture.", ERROR));
}

/**
 * 床のテクスチャを貼る
 */
void	set_floor_texture(t_game *game, t_ray *ray, int y, int x)
{
	int	color;

	if (y > ray->wall_end_y)
	{
		color = game->mapinfo.floor_rgb[0] * 256 * 256
			+ game->mapinfo.floor_rgb[1] * 256 + game->mapinfo.floor_rgb[2];
		game->view_pixels[y][x] = color;
	}
	else
		free_exit(game, err_msg("can't set floor texture.", ERROR));
}
