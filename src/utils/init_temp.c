/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:46:23 by mnakashi          #+#    #+#             */
/*   Updated: 2024/09/08 14:55:12 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_temp(t_temp *temp)
{
	temp->map_count = 0;
	temp->map_path[0] = '\0';
	temp->player_flag = false;
	temp->player_direction = '\0';
	temp->player_mapx = 0;
	temp->player_mapy = 0;
	temp->texture_size = 64;
	temp->max_width = 0;
	temp->dirgb[0] = "NO";
	temp->dirgb[1] = "WE";
	temp->dirgb[2] = "SO";
	temp->dirgb[3] = "EA";
	temp->dirgb[4] = "C";
	temp->dirgb[5] = "F";
	temp->dirgb_flag[0] = false;
	temp->dirgb_flag[1] = false;
	temp->dirgb_flag[2] = false;
	temp->dirgb_flag[3] = false;
	temp->dirgb_flag[4] = false;
	temp->dirgb_flag[5] = false;
}
