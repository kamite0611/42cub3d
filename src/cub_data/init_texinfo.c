/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:10:38 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 19:22:56 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_texture(t_cub_data *cubdata, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(cubdata->mlx, path,
			&cubdata->texinfo.size, &cubdata->texinfo.size);
	printf("img %p\n", texture->img);
	if (texture->img == NULL)
		return (err_msg("mlx_xpm_file_to_image() error.", ERR));
	texture->addr = (int *)mlx_get_data_addr(texture->img, &texture->bits_pixel,
			&texture->size_line, &texture->endian);
	if (texture->addr == NULL)
		return (err_msg("mlx_get_data_addr() error.", ERR));
	return (SUCCESS);
}

int	init_texinfo(t_cub_data *cubdata)
{
	t_texinfo	*texinfo;
	t_mapinfo	mapinfo;

	texinfo = &cubdata->texinfo;
	mapinfo = cubdata->mapinfo;
	if (init_texture(cubdata, &texinfo->north, mapinfo.no_path))
		return (ERR);
	if (init_texture(cubdata, &texinfo->south, mapinfo.so_path))
		return (ERR);
	if (init_texture(cubdata, &texinfo->west, mapinfo.we_path))
		return (ERR);
	if (init_texture(cubdata, &texinfo->east, mapinfo.ea_path))
		return (ERR);
	return (SUCCESS);
}
