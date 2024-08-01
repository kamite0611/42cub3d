/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:05:11 by akamite           #+#    #+#             */
/*   Updated: 2024/08/02 00:02:32 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * プレイヤー情報に値を入れる
 * map_xy, direction は ファイル分析の段階で入れる
 */
void	init_player_vec(t_player *player)
{
	if (player->direction == 'N')
	{
		player->vec_x_dir = 0;
		player->vec_y_dir = -1;
		player->vec_x_camera = VIEWING_ANGLE;
		player->vec_y_camera = 0;
	}
	if (player->direction == 'S')
	{
		player->vec_x_dir = 0;
		player->vec_y_dir = 1;
		player->vec_x_camera = -VIEWING_ANGLE;
		player->vec_y_camera = 0;
	}
	if (player->direction == 'E')
	{
		player->vec_x_dir = 1;
		player->vec_y_dir = 0;
		player->vec_x_camera = 0;
		player->vec_y_camera = VIEWING_ANGLE;
	}
	if (player->direction == 'W')
	{
		player->vec_x_dir = -1;
		player->vec_y_dir = 0;
		player->vec_x_camera = 0;
		player->vec_y_camera = -VIEWING_ANGLE;
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
	player->vec_x_dir = 0.0;
	player->vec_y_dir = 0.0;
	player->vec_x_camera = 0.0;
	player->vec_y_camera = 0.0;
}
