/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:46:23 by akamite           #+#    #+#             */
/*   Updated: 2024/07/31 02:12:12 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (args_checker(argc, argv))
		return (ERR);
	initialize_game(&game, argv[1]);
	init_game(&game);
	render_view(&game);
	mlx_loop(game.mlx);
	// system("leaks -atExit -- ./cub3D");
	free_exit(&game, SUCCESS);
	return (SUCCESS);
}
