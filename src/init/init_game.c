/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:59:33 by akamite           #+#    #+#             */
/*   Updated: 2024/07/31 02:12:12 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_view_pixels(t_game *game)
{
	game->view_pixels = calloc(sizeof *game->view_pixels, game->win_height);
}

/**
 * t_game 全体の構造体
 * mapinfo,mlx など処理に必要なデータを全てこの段階で入れる
 */
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_exit(game, err_msg("mlx_init() Error.", ERR));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		free_exit(game, err_msg("mlx_new_window() Error.", ERR));
	if (init_mapinfo(&game->mapinfo))
		free_exit(game, ERR);
	put_mapinfo(&game->mapinfo);
}

int	initialize_game(t_game *game, char *map_path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->view_pixels = NULL;
	initialize_mapinfo(&game->mapinfo, map_path);
	return (SUCCESS);
}
