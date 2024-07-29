/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:31:35 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 02:03:57 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	initialize_mapinfo(t_mapinfo *mapinfo, char *map_path)
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

static int	initialize_texinfo(t_texinfo *text_data)
{
	text_data->north = NULL;
	text_data->south = NULL;
	text_data->west = NULL;
	text_data->east = NULL;
	text_data->size = TEX_SIZE;
	return (SUCCESS);
}

int	initialize_cub_data(t_cub_data *cub_data, char *map_path)
{
	cub_data->mlx = NULL;
	cub_data->win = NULL;
	cub_data->win_height = WIN_HEIGHT;
	cub_data->win_height = WIN_WIDTH;
	initialize_texinfo(&cub_data->texinfo);
	initialize_mapinfo(&cub_data->mapinfo, map_path);
	return (SUCCESS);
}
