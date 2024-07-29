/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:31:35 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 20:34:46 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int initialize_cub_data(t_cub_data *cub_data)
{
	cub_data->mlx = NULL;
	cub_data->win = NULL;
	cub_data->win_height = WIN_HEIGHT;
	cub_data->win_height = WIN_WIDTH;
	return SUCCESS;
}
