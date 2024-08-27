/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:28:36 by akamite           #+#    #+#             */
/*   Updated: 2024/08/24 15:32:09 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_game *game)
{
	if (key == XK_Escape)
		finish_game(game);
	if (key == XK_w)
		move_forward(&game->player);
	if (key == XK_a)
		move_left(&game->player);
	if (key == XK_s)
		move_backward(&game->player);
	if (key == XK_d)
		move_right(&game->player);
	if (key == XK_Left)
		rotate_left(&game->player);
	if (key == XK_Right)
		rotate_right(&game->player);
	render_raycasting(game);
	return (SUCCESS);
}

//
// static int	key_release_handler(int key, t_game *game)
// {
// 	if (key == XK_Escape)
// 		finish_game(game);
// 	if (key == XK_w && game->player.map_x == 1)
// 		game->player.map_x = 0;
// 	if (key == XK_s && game->player.map_y == -1)
// 		game->player.map_y = 0;
// 	if (key == XK_a && game->player.map_x == -1)
// 		game->player.map_x += 1;
// 	if (key == XK_d && game->player.map_x == 1)
// 		game->player.map_x -= 1;
// 	// if (key == XK_Left && game->player. <= 1)
// 	// 	game->player.rotate = 0;
// 	// if (key == XK_Right && game->player.rotate >= -1)
// 	// 	game->player.rotate = 0;
// 	return (0);
// }
//

void	hooks_keys(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, finish_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press_handler, game);
}
