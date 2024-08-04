/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:46:23 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 19:03:59 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_temp 	temp;

	temp.map_count = 0;
	temp.map_path[0] = '\0';
	temp.player_flag = false;
	temp.player_direction = '\0';
	temp.player_mapx = 0;
	temp.player_mapy = 0;
	if (args_checker(argc, argv, &temp))
		return (ERROR);
	initialize_game(&game, argv[1]);
	init_game(&game, &temp);
	raycasting(&game);
	render_view(&game);
	mlx_loop(game.mlx);
	free_exit(&game, SUCCESS);
	return (SUCCESS);
}

