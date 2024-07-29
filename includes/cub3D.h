/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:05:10 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 20:12:46 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

typedef struct s_cub_data
{
  void *mlx;
  void *win;
} t_cub_data;

#define ERR_USAGE "Usage: ./cub3D <path/to/map.cub>"

#include <X11/keysym.h>
#include <X11/X.h>

/** Utils */
int err_msg(char *msg, int status);

#endif
