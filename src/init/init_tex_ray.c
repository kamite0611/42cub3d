/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:55:50 by akamite           #+#    #+#             */
/*   Updated: 2024/08/10 23:22:49 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex_ray(t_game *game, t_ray *ray, t_tex_ray *tex_ray)
{
	const int	tex_size = game->texinfo.size;

	initialize_tex_ray(tex_ray);
	tex_ray->x = (int)(ray->wall_x * tex_size);
	if ((ray->side == 0 && ray->vec_dir_x < 0) || (ray->side == 1
			&& ray->vec_dir_y > 0))
		tex_ray->x = tex_size - tex_ray->x - 1;
	tex_ray->step = 1.0 * tex_size / ray->wall_height;
	tex_ray->pos = (ray->wall_start_y - game->win_height / 2 + ray->wall_height
			/ 2) * tex_ray->step;
}

/**
 *
 */
void	initialize_tex_ray(t_tex_ray *tex_ray)
{
	tex_ray->x = 0;
	tex_ray->y = 0;
	tex_ray->step = 0.0;
	tex_ray->pos = 0.0;
}
