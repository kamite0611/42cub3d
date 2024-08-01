/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:05:11 by akamite           #+#    #+#             */
/*   Updated: 2024/08/01 22:08:02 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * プレイヤー情報に値を入れる
 */
void	init_player(t_player *player)
{
}

/**
 * プレイヤー情報を初期化
 */
void	initialize_player(t_player *player)
{
	player->direction = '\0';
	player->map_x = 0;
	player->map_y = 0;
	player->vec_x_dir = 0;
	player->vec_y_dir = 0;
	player->vec_x_camera = 0;
	player->vec_y_camera = 0;
}
