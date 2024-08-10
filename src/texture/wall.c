/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:46:48 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 15:52:07 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_color(t_game *game, t_ray *ray)
{
	(void)game;
	if (ray->side == 1)
		return (ray->vec_dir_y < 0 ? 100000 : 200000);
	else
		return (ray->vec_dir_x < 0 ? 600000 : 700000);
}
