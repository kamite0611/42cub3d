/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:46:23 by akamite           #+#    #+#             */
/*   Updated: 2024/08/12 18:31:07 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_temp	temp;

	temp.map_count = 0;
	temp.map_path[0] = '\0';
	temp.player_flag = false;
	temp.player_direction = '\0';
	temp.player_mapx = 0;
	temp.player_mapy = 0;
	temp.texture_size = 64;
	if (args_checker(argc, argv, &temp))
		return (ERROR);
	initialize_game(&game, argv[1]);
	init_game(&game, &temp);
	render_raycasting(&game);
	hooks_keys(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	free_exit(&game, SUCCESS);
	return (SUCCESS);
}
