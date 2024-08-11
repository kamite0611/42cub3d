/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:46:48 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 23:21:39 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**get_wall_texture(t_game *game, t_ray *ray)
{
	(void)game;
	if (ray->side == 1)
	{
		if (ray->vec_dir_y < 0)
			return (game->texinfo.tex_west /** WEST */);
		else
			return (game->texinfo.tex_east /** EAST */);
	}
	else
	{
		if (ray->vec_dir_x < 0)
			return (game->texinfo.tex_south /** SOUTH */);
		else
			return (game->texinfo.tex_north /** NORTH */);
	}
}

int	get_wall_color(t_game *game, int **wall_tex, t_tex_ray *tex_ray)
{
	tex_ray->y = (int)tex_ray->pos & (game->texinfo.size - 1);
	tex_ray->pos += tex_ray->step;
	return (wall_tex[tex_ray->y][tex_ray->x]);
}
