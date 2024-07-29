/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 20:42:45 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define ERR 1
#define SUCCESS 0

#define WIN_HEIGHT 480
#define WIN_WIDTH 640

#include "libft.h"

#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>

typedef struct s_cub_data
{
  void *mlx;
  void *win;
  unsigned int win_height;
  unsigned int win_width;
} t_cub_data;

#define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"



/** CubData */
int initialize_cub_data(t_cub_data *cub_data);



/** Utils */
int err_msg(char *msg, int status);

#endif
