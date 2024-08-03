/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 01:40:15 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ------------------- defines ------------------- */

# define ERROR 1
# define SUCCESS 0

# define WIN_HEIGHT 480
# define WIN_WIDTH 640
// # define WIN_HEIGHT 200
// # define WIN_WIDTH 300
# define TEX_SIZE 64
# define VIEWING_ANGLE 0.66 /** 視野角 */
# define MOVESPEED 0.05
# define ROTSPEED 0.05

# define WALL_C '1'

# define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"
# define ERR_MALLOC "Error: malloc() failed."
# define ERR_MSG "ERROR\n"

/* ------------------- includes ------------------- */

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/* ------------------- structs ------------------- */

/**
 * ピクセル編集可能な画像情報
 */
typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}			t_img;

/**
 * マップファイル情報
 */
typedef struct s_mapinfo
{
	char *path; /** argv[2] */

	/** xpmファイルパス */
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	/** str配列のマップデータ */
	char	**map;

	/** 地図の最大横幅・縦幅 */
	int		map_height;
	int		map_width;

	int		floor_rgb[3];
	int		ceiling_rgb[3];

	int		line_count;
}			t_mapinfo;

/**
画面座標
(0, 0) -----> x (正の方向)
 |
 |
 v
 y (正の方向)
 */
/**
 * レイキャスティングで使用する光線情報
 */
typedef struct s_ray
{
	/** カメラ平面 */
	double	camera_x;

	/** 垂直方向の場合1, 水平方向の場合0 */
	int		side;

	/** マップ上の座標 */
	int		map_x;
	int		map_y;

	/** レイがグリット上で進む数 */
	int		step_x;
	int		step_y;

	/** レイの方向ベクトル */
	double	vec_dir_x;
	double	vec_dir_y;

	/**  */
	double	sidedist_x;
	double	sidedist_y;

	/**  */
	double	deltadist_x;
	double	deltadist_y;

	/** 壁の高さ */
	int		wall_height;
	/** 壁までの距離 */
	double	wall_dist;

	int		wall_start_y;
	int		wall_end_y;

}			t_ray;

/**
 * プレイヤー情報
 */
typedef struct s_player
{
	/** 方角 N,S,E,W */
	char	direction;

	/** マップ上の座標 */
	double	map_x;
	double	map_y;

	/** プレイヤー向きベクトル */
	double vec_dir_x; /** x方向ベクトル */
	double vec_dir_y; /** y方向ベクトル */

	/** カメラ方向ベクトル */
	/** プレイヤーの視界の中心から片方の端までのベクトル */
	double vec_plane_x /** x方向ベクトル */;
	double vec_plane_y /** y方向ベクトル */;
}			t_player;

/**
 * cub3d全体で使用する構造体
 */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;

	/** 画面全体のピクセル 640*480 */
	int		**view_pixels;

	t_mapinfo mapinfo; /** Map関係 */
	t_player player /** プレイヤー情報 */;
	t_ray ray /** 光線情報 */;
}			t_game;

typedef struct s_temp
{
	int		map_count;
	char	map_path[4096];
	char	player_direction;
	int		player_mapx;
	int		player_mapy;
}			t_temp;

/* ------------------- functions ------------------- */

/** Actions */
void		hooks_keys(t_game *game);

void		move_forward(t_player *player);
void		move_backward(t_player *player);
void		move_right(t_player *player);
void		move_left(t_player *player);

void		rotate_left(t_player *player);
void		rotate_right(t_player *player);

/** inits */
int			new_init_mapinfo(t_game *game, t_mapinfo *mapinfo, t_temp *temp);
void		init_mapinfo(t_game *game, t_mapinfo *mapinfo);
int			initialize_mapinfo(t_mapinfo *mapinfo, char *map_path);

void		init_game(t_game *game, t_temp *temp);
void		init_view_pixels(t_game *game);
int			initialize_game(t_game *game, char *map_path);

void		init_img(t_game *game, t_img *image, int width, int height);
void		initialize_img(t_img *image);

void		init_player_vec(t_player *player);
void		initialize_player(t_player *player);

void		init_ray(t_ray *ray, t_player *player, int x);
void		initialize_ray(t_ray *ray);

/** Exit */
void		free_exit(t_game *game, int status);
int			finish_game(t_game *game);

/** map_check */
int			args_checker(int argc, char *argv[], t_temp *temp);

/** Render */
void		raycasting(t_game *game);
void		render_view(t_game *game);
void		render_raycasting(t_game *game);

bool		is_hit_wall(t_game *game, t_ray *ray);

/** Utils */
int			err_msg(char *msg, int status);
void		put_mapinfo(t_mapinfo *mapinfo);
void		put_player(t_player *player);
void		put_ray(t_ray *ray);
void		free_tab(void **tab);

#endif
