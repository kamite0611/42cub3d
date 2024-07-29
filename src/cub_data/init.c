/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:59:33 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 23:24:42 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_tex_data(t_tex_data *tex_data)
{
}

void init_cub_data(t_cub_data *cub_data)
{
	cub_data->mlx = mlx_init();
	if (!cub_data->mlx)
		free_exit(cub_data, err_msg("mlx_init() Error.", ERR));

	cub_data->win = mlx_new_window(cub_data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!cub_data->win)
		free_exit(cub_data, err_msg("mlx_new_window() Error.", ERR));
}
