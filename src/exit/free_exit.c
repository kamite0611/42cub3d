/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:56:49 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 22:44:44 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * t_mapinfoの中身でmallocしているものをfreeする
 */
static void	free_mapinfo(t_mapinfo *mapinfo)
{
	if (mapinfo->no_path)
		free(mapinfo->no_path);
	if (mapinfo->so_path)
		free(mapinfo->so_path);
	if (mapinfo->we_path)
		free(mapinfo->we_path);
	if (mapinfo->ea_path)
		free(mapinfo->ea_path);
	if (mapinfo->map)
		free_tab((void **)mapinfo->map);
}

/**
 *
 */
static void	free_texinfo(t_texinfo *texinfo)
{
	if (texinfo->tex_north)
		free_tab((void **)texinfo->tex_north);
	if (texinfo->tex_south)
		free_tab((void **)texinfo->tex_south);
	if (texinfo->tex_west)
		free_tab((void **)texinfo->tex_west);
	if (texinfo->tex_south)
		free_tab((void **)texinfo->tex_south);
}

/**
 * t_gameの中身でmallocしているものをfreeする
 */
static void	free_game(t_game *game)
{
	if (game)
	{
		free_mapinfo(&game->mapinfo);
		free_texinfo(&game->texinfo);
		free_tab((void **)game->view_pixels);
	}
}

/**
 * 全てをfree後,statusで渡された値でexitする
 */
void	free_exit(t_game *game, int status)
{
	if (!game)
		exit(status);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_game(game);
	exit(status);
}

int	finish_game(t_game *game)
{
	free_exit(game, 0);
	return (0);
}
