/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:31:35 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 00:37:00 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int initialize_mapinfo(t_mapinfo *mapinfo, char *map_path)
{
	mapinfo->path = map_path;
	mapinfo->content = NULL;
	mapinfo->line_count = 0;
	return SUCCESS;
}

int initialize_texinfo(t_texinfo *text_data)
{
	text_data->north = NULL;
	text_data->south = NULL;
	text_data->west = NULL;
	text_data->east = NULL;

	text_data->size = TEX_SIZE;
	return SUCCESS;
}

int initialize_cub_data(t_cub_data *cub_data, char *map_path)
{
	cub_data->mlx = NULL;
	cub_data->win = NULL;
	cub_data->win_height = WIN_HEIGHT;
	cub_data->win_height = WIN_WIDTH;
	initialize_texinfo(&cub_data->texinfo);
	initialize_mapinfo(&cub_data->mapinfo, map_path);
	return SUCCESS;
}
