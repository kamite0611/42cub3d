/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:08:37 by akamite           #+#    #+#             */
/*   Updated: 2024/08/24 15:32:34 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_view(t_game *game)
{
	t_img	image;
	int		y;
	int		x;

	init_img(game, &image, game->win_width, game->win_height);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			image.addr[y * (image.size_line / 4) + x] = game->view_pixels[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

void	render_raycasting(t_game *game)
{
	init_view_pixels(game);
	raycasting(game);
	render_view(game);
}

int	render(t_game *game)
{
	render_raycasting(game);
	return (0);
}
