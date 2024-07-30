/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/07/31 02:04:21 by akamite          ###   ########.fr       */
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

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_mapinfo
{
	char *path; /** argv[2] */

	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	char	**map;

	int		floor_rgb[3];
	int		ceiling_rgb[3];

	int		line_count;
	int		map_height_count;
}			t_mapinfo;

typedef struct s_cub_data
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;

	/** 画面全体のピクセル 640*480 */
	int		**view_pixels;

	t_mapinfo mapinfo; /** Map関係 */
}			t_cub_data;

/* ------------------- functions ------------------- */

/** inits */
int			init_mapinfo(t_mapinfo *mapinfo);
int			initialize_mapinfo(t_mapinfo *mapinfo, char *map_path);

void		init_cub_data(t_cub_data *cub_data);
int			initialize_cub_data(t_cub_data *cub_data, char *map_path);

void		init_img(t_cub_data *cubdata, t_img *image, int width, int height);
void		initialize_img(t_img *image);

/** Exit */
void		free_exit(t_cub_data *cub_data, int status);

/** map_check */
int			args_checker(int argc, char *argv[]);

/** Render */
void		render_view(t_cub_data *cubdata);

/** Utils */
int			err_msg(char *msg, int status);
void		put_mapinfo(t_mapinfo *mapinfo);
void		free_tab(void **tab);

#endif
