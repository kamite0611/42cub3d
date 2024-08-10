/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:46:48 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 22:38:44 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_color(t_game *game, t_ray *ray)
{
	(void)game;
	if (ray->side == 1)
	{
		if (ray->vec_dir_y < 0)
			return ((100000) /** WEST */);
		else
			return ((200000) /** EAST */);
	}
	else
	{
		if (ray->vec_dir_x < 0)
			return ((600000) /** SOUTH */);
		else
			return ((700000) /** NORTH */);
	}
}
