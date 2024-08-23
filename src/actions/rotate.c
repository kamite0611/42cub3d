/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:04:50 by akamite           #+#    #+#             */
/*   Updated: 2024/08/23 00:02:26 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Rotate viewpoint.
 * https://ja.wikipedia.org/wiki/%E5%9B%9E%E8%BB%A2%E8%A1%8C%E5%88%97
 * newX = x * cos(θ) - y * sin(θ)
 * newY = y * sin(θ) + y * cos(θ)
 */
static void	rotate(t_player *player, double rotspeed)
{
	double	tmp_x;

	tmp_x = player->vec_dir_x;
	player->vec_dir_x = player->vec_dir_x * cos(rotspeed) - player->vec_dir_y
		* sin(rotspeed);
	player->vec_dir_y = tmp_x * sin(rotspeed) + player->vec_dir_y
		* cos(rotspeed);
	tmp_x = player->vec_plane_x;
	player->vec_plane_x = player->vec_plane_x * cos(rotspeed)
		- player->vec_plane_y * sin(rotspeed);
	player->vec_plane_y = tmp_x * sin(rotspeed) + player->vec_plane_y
		* cos(rotspeed);
}

void	rotate_left(t_player *player)
{
	rotate(player, -ROTSPEED);
}

void	rotate_right(t_player *player)
{
	rotate(player, ROTSPEED);
}
