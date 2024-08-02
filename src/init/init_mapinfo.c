/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:00 by akamite           #+#    #+#             */
/*   Updated: 2024/08/03 01:36:42 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Map情報をファイルから取得する
 */
void	init_mapinfo(t_game *game, t_mapinfo *mapinfo)
{
	char	**map;

	/** @TODO ファイルから取得する */
	mapinfo->no_path = ft_strdup("textures/bookshelf.xpm");
	mapinfo->so_path = ft_strdup("textures/bookshelf.xpm");
	mapinfo->we_path = ft_strdup("textures/bookshelf.xpm");
	mapinfo->ea_path = ft_strdup("textures/bookshelf.xpm");
	mapinfo->line_count = 22;
	mapinfo->floor_rgb[0] = 53;
	mapinfo->floor_rgb[1] = 41;
	mapinfo->floor_rgb[2] = 34;
	mapinfo->ceiling_rgb[0] = 45;
	mapinfo->ceiling_rgb[1] = 33;
	mapinfo->ceiling_rgb[2] = 27;
	map = malloc(sizeof(char *) * 14);
	map[0] = ft_strdup("111111111111111");
	map[1] = ft_strdup("111111000111111");
	map[2] = ft_strdup("111110000011111");
	map[3] = ft_strdup("111100000001111"); /** Nを0にする */
	map[4] = ft_strdup("111000000000111");
	map[5] = ft_strdup("110000000000011");
	map[6] = ft_strdup("100001111100001");
	map[7] = ft_strdup("110000111000011");
	map[8] = ft_strdup("111000010000111");
	map[9] = ft_strdup("111100000001111");
	map[10] = ft_strdup("111110000011111");
	map[11] = ft_strdup("111111000111111");
	map[12] = ft_strdup("111111111111111");
	map[13] = NULL;
	mapinfo->map = map;
	game->player.direction = 'N';
	game->player.map_x = 7.5; /** プレイヤーのIndex + 0.5 */
	game->player.map_y = 3.5; /** プレイヤーのIndex + 0.5 */
}

int	initialize_mapinfo(t_mapinfo *mapinfo, char *map_path)
{
	mapinfo->path = map_path;
	mapinfo->line_count = 0;
	mapinfo->no_path = NULL;
	mapinfo->so_path = NULL;
	mapinfo->we_path = NULL;
	mapinfo->ea_path = NULL;
	mapinfo->floor_rgb[0] = 0;
	mapinfo->floor_rgb[1] = 0;
	mapinfo->floor_rgb[2] = 0;
	mapinfo->ceiling_rgb[0] = 0;
	mapinfo->ceiling_rgb[1] = 0;
	mapinfo->ceiling_rgb[2] = 0;
	return (SUCCESS);
}
