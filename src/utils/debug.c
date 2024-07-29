/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:18:50 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 01:24:10 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void put_mapinfo(t_mapinfo *mapinfo)
{
	printf("################## mapinfo ##################\n");
	printf("path\t\t: \"%s\" \n", mapinfo->path);
	printf("no_path\t\t: \"%s\" \n", mapinfo->no_path);
	printf("so_path\t\t: \"%s\" \n", mapinfo->so_path);
	printf("ea_path\t\t: \"%s\" \n", mapinfo->ea_path);
	printf("line_count\t: %d\n", mapinfo->line_count);
}
