/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:39:51 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 23:30:36 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 天井のテクスチャを貼る
 */
int	get_ceiling_color(t_game *game)
{
	int	color;

	color = game->mapinfo.ceiling_rgb[0] * 256 * 256
		+ game->mapinfo.ceiling_rgb[1] * 256 + game->mapinfo.ceiling_rgb[2];
	return (color);
}

/**
 * 床のテクスチャを貼る
 */
int	get_floor_color(t_game *game)
{
	int	color;

	color = game->mapinfo.floor_rgb[0] * 256 * 256 + game->mapinfo.floor_rgb[1]
		* 256 + game->mapinfo.floor_rgb[2];
	return (color);
}
