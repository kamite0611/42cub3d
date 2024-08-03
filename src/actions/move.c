/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:51:14 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 01:04:34 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player)
{
	player->map_x = player->map_x + player->vec_dir_x * MOVESPEED;
	player->map_y = player->map_y + player->vec_dir_y * MOVESPEED;
}

void	move_backward(t_player *player)
{
	player->map_x = player->map_x - player->vec_dir_x * MOVESPEED;
	player->map_y = player->map_y - player->vec_dir_y * MOVESPEED;
}

void	move_left(t_player *player)
{
	player->map_x = player->map_x + player->vec_dir_y * MOVESPEED;
	player->map_y = player->map_y - player->vec_dir_x * MOVESPEED;
}

void	move_right(t_player *player)
{
	player->map_x = player->map_x - player->vec_dir_y * MOVESPEED;
	player->map_y = player->map_y + player->vec_dir_x * MOVESPEED;
}
