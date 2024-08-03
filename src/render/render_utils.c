/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:17:01 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 00:29:11 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 壁に当たったかどうか
 */
bool	is_hit_wall(t_game *game, t_ray *ray)
{
	char	**map;

	map = game->mapinfo.map;
	if (map[ray->map_y][ray->map_x] == WALL_C)
		return (true);
	return (false);
}
