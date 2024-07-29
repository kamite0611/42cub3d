/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:00 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 00:27:28 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

const void set_content(t_mapinfo *mapinfo)
{
}

const void alloc_mapinfo(t_mapinfo *mapinfo)
{
}

void init_mapinfo(t_cub_data *cubdata)
{
	alloc_mapinfo(&cubdata->mapinfo);
}
