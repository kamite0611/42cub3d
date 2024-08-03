/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:59:33 by akamite           #+#    #+#             */
/*   Updated: 2024/08/02 19:05:34 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * t_game.view_pixels の初期値を作成
 * 640*480 int配列を確保し保存する
 */
void	init_view_pixels(t_game *game)
{
	int	i;

	i = 0;
	if (game->view_pixels)
		free_tab((void **)game->view_pixels);
	game->view_pixels = ft_calloc(sizeof(int **), game->win_height + 1);
	if (!game->view_pixels)
		free_exit(game, err_msg(ERR_MALLOC, ERROR));
	while (i < game->win_height)
	{
		game->view_pixels[i] = ft_calloc(sizeof(int **), game->win_width + 1);
		if (!game->view_pixels[i])
			free_exit(game, err_msg(ERR_MALLOC, ERROR));
		i++;
	}
}

/**
 * t_game 全体の構造体
 * mapinfo,mlx など処理に必要なデータを全てこの段階で入れる
 */
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_exit(game, err_msg("mlx_init() Error.", ERROR));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		free_exit(game, err_msg("mlx_new_window() Error.", ERROR));
	/** init */
	init_mapinfo(game, &game->mapinfo);
	init_player_vec(&game->player);
	init_view_pixels(game);
	/** debug */
	put_mapinfo(&game->mapinfo);
	put_player(&game->player);
}

/**
 * t_game 構造体を初期化する
 */
int	initialize_game(t_game *game, char *map_path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->view_pixels = NULL;
	initialize_mapinfo(&game->mapinfo, map_path);
	initialize_player(&game->player);
	initialize_ray(&game->ray);
	return (SUCCESS);
}
