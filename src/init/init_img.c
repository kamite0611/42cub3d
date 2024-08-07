/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:10:38 by akamite           #+#    #+#             */
/*   Updated: 2024/08/07 19:26:18 by mnakashi         ###   ########.fr       */
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

void	init_texture_img(t_game *game, t_img *image, char *path, t_temp *temp)
{
	initialize_img(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &temp->texture_size, &temp->texture_size);
	if (image->img == NULL)
		free_exit(game, err_msg(ERR_MLX, 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

static int	*xpm_to_img(t_game *game, char *path, t_temp *temp)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(game, &tmp, path, temp);
	buffer = ft_calloc(1, sizeof * buffer * 64 * 64);
	if (!buffer)
		free_exit(game, err_msg(ERR_MALLOC, 1));
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			buffer[y * 64 + x] = tmp.addr[y * 64 + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}


int	init_texture(t_game *game, t_temp *temp)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		free_exit(game, err_msg(ERR_MALLOC, 1));
	game->textures[0] = xpm_to_img(game, game->mapinfo.no_path, temp);
	game->textures[1] = xpm_to_img(game, game->mapinfo.so_path, temp);
	game->textures[2] = xpm_to_img(game, game->mapinfo.ea_path, temp);
	game->textures[3] = xpm_to_img(game, game->mapinfo.we_path, temp);
	return (SUCCESS);
}
