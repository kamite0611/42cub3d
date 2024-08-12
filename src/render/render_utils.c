/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:17:01 by akamite           #+#    #+#             */
/*   Updated: 2024/08/12 15:40:04 by mnakashi         ###   ########.fr       */
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
	// マップの境界をチェック
    if (ray->map_x < 0 || ray->map_x >= game->mapinfo.map_width ||
        ray->map_y < 0 || ray->map_y >= game->mapinfo.map_height) {
        return (false); // 境界外の場合は衝突と見なさない
    }
	if (map[ray->map_y][ray->map_x] == WALL_C)
		return (true);
	return (false);
}
