/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 18:56:29 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ------------------- defines ------------------- */

# define ERR 1
# define SUCCESS 0

# define WIN_HEIGHT 480
# define WIN_WIDTH 640
# define TEX_SIZE 64

# define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"

/* ------------------- includes ------------------- */

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/* ------------------- structs ------------------- */

typedef struct s_mapinfo
{
	char *path; /** argv[2] */

	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;

	char		**map;

	int			floor_rgb[3];
	int			ceiling_rgb[3];

	int			line_count;
	int			map_height_count;
}				t_mapinfo;

typedef struct s_texture
{
	void		*img;
	int			*addr;
	int			bits_pixel;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_texinfo
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;

	int			size;
}				t_texinfo;

typedef struct s_cub_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;

	t_texinfo texinfo; /** テクスチャ関係 */
	t_mapinfo mapinfo; /** Map関係 */
}				t_cub_data;

/* ------------------- functions ------------------- */

/** CubData */
int				init_mapinfo(t_mapinfo *mapinfo);
int				init_texinfo(t_cub_data *cubdata);
void			init_cub_data(t_cub_data *cub_data);
int				initialize_cub_data(t_cub_data *cub_data, char *map_path);

/** Exit */
void			free_exit(t_cub_data *cub_data, int status);

/** map_check */
int				args_checker(int argc, char *argv[]);

/** Utils */
int				err_msg(char *msg, int status);
void			put_mapinfo(t_mapinfo *mapinfo);
void			free_strarr(char *str_arr[]);

#endif
