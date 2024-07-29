/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 01:08:36 by akamite          ###   ########.fr       */
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
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_mapinfo
{
  char *path; /** argv[2] */

  char *no_path;
  char *so_path;
  char *we_path;
  char *ea_path;

  int line_count;
} t_mapinfo;


typedef struct s_texinfo
{
  char *north;
  char *south;
  char *west;
  char *east;
	int size;
} t_texinfo;


typedef struct s_cub_data
{
  void *mlx;
  void *win;
  int win_height;
  int win_width;

  t_texinfo texinfo; /** テクスチャ関係 */
  t_mapinfo mapinfo; /** Map関係 */
} t_cub_data;

#define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"


/** CubData */
void init_mapinfo(t_cub_data *cubdata);
void init_cub_data(t_cub_data *cub_data);
int initialize_cub_data(t_cub_data *cub_data, char *map_path);

/** Exit */
void free_exit(t_cub_data *cub_data, int status);

/** Utils */
int err_msg(char *msg, int status);

/** map_check */
int args_checker(int argc, char *argv[]);

#endif
