/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:54:54 by akamite           #+#    #+#             */
/*   Updated: 2024/08/03 19:00:08 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

/**
 * 光線を画面の横幅分出す
 */
void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < game->win_width)
	{
		init_ray(&ray, &game->player, x);
		put_ray(&ray);
		x++;
	}
}
