/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:17:01 by akamite           #+#    #+#             */
/*   Updated: 2024/08/22 23:52:37 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_hit_wall(t_game *game, t_ray *ray)
{
	char	**map;

	map = game->mapinfo.map;
	if (ray->map_x < 0 || ray->map_x >= game->mapinfo.map_width
		|| ray->map_y < 0 || ray->map_y >= game->mapinfo.map_height)
		return (false);
	if (map[ray->map_y][ray->map_x] == WALL_C)
		return (true);
	return (false);
}
