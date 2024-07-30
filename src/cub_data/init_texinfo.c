/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:10:38 by akamite           #+#    #+#             */
/*   Updated: 2024/07/31 00:56:04 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_texture(t_cub_data *cubdata, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(cubdata->mlx, path,
			&cubdata->texinfo.size, &cubdata->texinfo.size);
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

/**
 * MLX ピクセル画像データを t_img 構造体に取得
 * t_img 画像データだけでなく、addr を書き換えることで1ピクセル単位で編集が可能
 */
void	init_img(t_cub_data *cubdata, t_img *image, int width, int height)
{
	initialize_img(image);
	image->img = mlx_new_image(cubdata->mlx, width, height);
	if (image->img == NULL)
		free_exit(cubdata, err_msg("mlx_xpm_file_to_image() error.", ERR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
		free_exit(cubdata, err_msg("mlx_get_data_addr() error.", ERR));
}
