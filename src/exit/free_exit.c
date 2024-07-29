/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:56:49 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 23:20:45 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

/**
 * t_cub_dataの中身でmallocしているものをfreeする
 */
void free_cub_data(t_cub_data *cub_data)
{
	(void)cub_data;
}


/**
 * 全てをfree後,statusで渡された値でexitする
 */
void free_exit(t_cub_data *cub_data, int status)
{
	if(!cub_data)
		exit(status);
	if (cub_data->win && cub_data->mlx)
		mlx_destroy_window(cub_data->mlx, cub_data->win);
	if (cub_data->mlx)
	{
		mlx_destroy_display(cub_data->mlx);
		mlx_loop_end(cub_data->mlx);
		free(cub_data->mlx);
	}
	free_cub_data(cub_data);
	exit(status);
}

