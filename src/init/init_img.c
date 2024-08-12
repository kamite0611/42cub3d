/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:10:38 by akamite           #+#    #+#             */
/*   Updated: 2024/08/12 17:28:17 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * MLX ピクセル画像データを t_img 構造体に取得
 * t_img 画像データだけでなく、addr を書き換えることで1ピクセル単位で編集が可能
 */
void	init_img(t_game *game, t_img *image, int width, int height)
{
	initialize_img(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		free_exit(game, err_msg("mlx_new_image() error.", ERROR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
		free_exit(game, err_msg("mlx_get_data_addr() error.", ERROR));
}

/**
 * MLX ピクセル画像データを t_img 構造体に取得
 * t_img 画像データだけでなく、addr を書き換えることで1ピクセル単位で編集が可能
 */
void	init_xpm_img(t_game *game, t_img *image, char *path)
{
	initialize_img(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size,
			&game->texinfo.size);
	if (image->img == NULL)
		free_exit(game, err_msg("mlx_xpm_file_to_image() error.", ERROR));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
		free_exit(game, err_msg("mlx_get_data_addr() error.", ERROR));
}

void	initialize_img(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
