/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:59:33 by akamite           #+#    #+#             */
/*   Updated: 2024/07/31 01:00:40 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_cub_data(t_cub_data *cub_data)
{
	cub_data->mlx = mlx_init();
	if (!cub_data->mlx)
		free_exit(cub_data, err_msg("mlx_init() Error.", ERR));
	cub_data->win = mlx_new_window(cub_data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Cub3D");
	if (!cub_data->win)
		free_exit(cub_data, err_msg("mlx_new_window() Error.", ERR));
	if (init_mapinfo(&cub_data->mapinfo))
		free_exit(cub_data, ERR);
	put_mapinfo(&cub_data->mapinfo);
}

int	initialize_cub_data(t_cub_data *cub_data, char *map_path)
{
	cub_data->mlx = NULL;
	cub_data->win = NULL;
	cub_data->win_width = WIN_WIDTH;
	cub_data->win_height = WIN_HEIGHT;
	initialize_mapinfo(&cub_data->mapinfo, map_path);
	return (SUCCESS);
}
