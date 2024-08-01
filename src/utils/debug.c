/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:18:50 by akamite           #+#    #+#             */
/*   Updated: 2024/08/01 23:42:07 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_str_arr(char **str_arr, char *name)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		printf("%s[%d]\t: \"%s\"\n", name, i, str_arr[i]);
		i++;
	}
}

void	put_mapinfo(t_mapinfo *mapinfo)
{
	printf("\n################## mapinfo ##################\n");
	printf("path\t\t: \"%s\"\n", mapinfo->path);
	printf("no_path\t\t: \"%s\"\n", mapinfo->no_path);
	printf("so_path\t\t: \"%s\"\n", mapinfo->so_path);
	printf("we_path\t\t: \"%s\"\n", mapinfo->we_path);
	printf("ea_path\t\t: \"%s\"\n", mapinfo->ea_path);
	printf("line_count\t: %d\n", mapinfo->line_count);
	printf("floor_rgb\t: R[%d], G[%d], B[%d]\n", mapinfo->floor_rgb[0],
		mapinfo->floor_rgb[1], mapinfo->floor_rgb[2]);
	printf("ceiling_rgb\t: R[%d], G[%d], B[%d]\n", mapinfo->ceiling_rgb[0],
		mapinfo->ceiling_rgb[1], mapinfo->ceiling_rgb[2]);
	put_str_arr(mapinfo->map, "map");
}

void	put_player(t_player *player)
{
	printf("\n################## player ##################\n");
	printf("direction\t: \'%c\'\n", player->direction);
	printf("map_xy\t\t: X[%lf] Y[%lf]\n", player->map_x, player->map_y);
	printf("vec_xy_dir\t: X[%lf] Y[%lf]\n", player->vec_x_dir,
		player->vec_y_dir);
	printf("vec_xy_camera\t: X[%lf] Y[%lf]\n", player->vec_x_camera,
		player->vec_y_camera);
}
