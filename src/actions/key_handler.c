/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:28:36 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 00:47:33 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_game *game)
{
	if (key == XK_Escape)
		finish_game(game);
	return (SUCCESS);
}

void	hooks_keys(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, finish_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press_handler, game);
}
