/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:10:38 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 18:58:11 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_texture(t_cub_data *cubdata, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(cubdata->mlx, path,
			&cubdata->texinfo.size, &cubdata->texinfo.size);
	if (!texture->img)
		return (ERR);
	texture->addr = (int *)mlx_get_data_addr(texture->img, &texture->bits_pixel,
			&texture->size_line, &texture->endian);
	if (!texture->addr)
		return (ERR);
	return (SUCCESS);
}

int	init_texinfo(t_cub_data *cubdata)
{
	t_texinfo	texinfo;
	t_mapinfo	mapinfo;

	texinfo = cubdata->texinfo;
	mapinfo = cubdata->mapinfo;
	init_texture(cubdata, &texinfo.north, mapinfo.no_path);
	init_texture(cubdata, &texinfo.south, mapinfo.so_path);
	init_texture(cubdata, &texinfo.west, mapinfo.we_path);
	init_texture(cubdata, &texinfo.east, mapinfo.ea_path);
	return (SUCCESS);
}
