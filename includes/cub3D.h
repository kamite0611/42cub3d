/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 23:54:59 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define ERR 1
#define SUCCESS 0

#define WIN_HEIGHT 480
#define WIN_WIDTH 640
#define TEX_SIZE 64


#include "libft.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "mlx.h"
#include <stdlib.h>

typedef struct s_tex_data
{
  char *north;
  char *south;
  char *west;
  char *east;
	int size;
} t_tex_data;


typedef struct s_cub_data
{
  char *map_path; /** argv[2] */

  void *mlx;
  void *win;
  int win_height;
  int win_width;

  t_tex_data tex_data;
} t_cub_data;

#define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"


/** CubData */
void init_cub_data(t_cub_data *cub_data);
int initialize_cub_data(t_cub_data *cub_data, char *map_path);

/** Exit */
void free_exit(t_cub_data *cub_data, int status);

/** Utils */
int err_msg(char *msg, int status);

/** parse */
int args_checker(int argc, char *argv[]);

#endif
