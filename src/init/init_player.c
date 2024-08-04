/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:05:11 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 00:29:11 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * プレイヤー情報に値を入れる
 * map_xy, direction は ファイル分析の段階で入れる
 */
void	init_player_vec(t_player *player)
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
 * プレイヤー情報を初期化
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
