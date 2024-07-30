/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:08:37 by akamite           #+#    #+#             */
/*   Updated: 2024/07/31 00:41:08 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_view(t_cub_data *cubdata)
{
	t_img	image;
	int		y;
	int		x;

	init_img(cubdata, &image, cubdata->win_width, cubdata->win_height);
	y = 0;
	while (y < cubdata->win_height)
	{
		x = 0;
		while (x < cubdata->win_width)
		{
			image.addr[y * (image.size_line / 4) + x] = 1000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cubdata->mlx, cubdata->win, image.img, 0, 0);
}
