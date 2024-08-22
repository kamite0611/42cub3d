/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:05:11 by akamite           #+#    #+#             */
/*   Updated: 2024/08/22 23:57:21 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_vec_ns(t_player *player)
{
	if (player->direction == 'N')
	{
		player->vec_dir_x = 0;
		player->vec_dir_y = -1;
		player->vec_plane_x = VIEWING_ANGLE;
		player->vec_plane_y = 0;
	}
	if (player->direction == 'S')
	{
		player->vec_dir_x = 0;
		player->vec_dir_y = 1;
		player->vec_plane_x = -VIEWING_ANGLE;
		player->vec_plane_y = 0;
	}
}

static void	init_player_vec_ew(t_player *player)
{
	if (player->direction == 'E')
	{
		player->vec_dir_x = 1;
		player->vec_dir_y = 0;
		player->vec_plane_x = 0;
		player->vec_plane_y = VIEWING_ANGLE;
	}
	if (player->direction == 'W')
	{
		player->vec_dir_x = -1;
		player->vec_dir_y = 0;
		player->vec_plane_x = 0;
		player->vec_plane_y = -VIEWING_ANGLE;
	}
}

/**
 * put values in player info.
 * map_xy, direction are put in at the file analysis stage
 */
void	init_player_vec(t_player *player)
{
	init_player_vec_ns(player);
	init_player_vec_ew(player);
}

/**
 * Initialise player information.
 */
void	initialize_player(t_player *player)
{
	player->direction = '\0';
	player->map_x = 0.0;
	player->map_y = 0.0;
	player->vec_dir_x = 0.0;
	player->vec_dir_y = 0.0;
	player->vec_plane_x = 0.0;
	player->vec_plane_y = 0.0;
}
