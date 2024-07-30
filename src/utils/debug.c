/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:18:50 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 19:26:59 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_mapinfo(t_mapinfo *mapinfo)
{
	printf("\n################## mapinfo ##################\n");
	printf("path\t\t: \"%s\" \n", mapinfo->path);
	printf("no_path\t\t: \"%s\" \n", mapinfo->no_path);
	printf("so_path\t\t: \"%s\" \n", mapinfo->so_path);
	printf("we_path\t\t: \"%s\" \n", mapinfo->we_path);
	printf("ea_path\t\t: \"%s\" \n", mapinfo->ea_path);
	printf("line_count\t: %d\n", mapinfo->line_count);
	printf("floor_rgb\t: R[%d], G[%d], B[%d]\n", mapinfo->floor_rgb[0],
		mapinfo->floor_rgb[1], mapinfo->floor_rgb[2]);
	printf("ceiling_rgb\t: R[%d], G[%d], B[%d]\n", mapinfo->ceiling_rgb[0],
		mapinfo->ceiling_rgb[1], mapinfo->ceiling_rgb[2]);
}

void	put_texture(t_texture *texture, char *name)
{
	printf("%s: { \n\
   img\t\t: %p\n\
   addr\t\t: %p\n\
   bits_pixel\t: %d\n\
   size_line\t: %d\n\
   endian\t: %d\n\
}\n",
			name,
			texture->img,
			texture->addr,
			texture->bits_pixel,
			texture->size_line,
			texture->endian);
}

void	put_texinfo(t_texinfo *texinfo)
{
	printf("\n################## texinfo ##################\n");
	printf("size\t\t: %d\n", texinfo->size);
	put_texture(&texinfo->north, "north");
	put_texture(&texinfo->south, "south");
	put_texture(&texinfo->east, "east");
	put_texture(&texinfo->west, "west");
}
