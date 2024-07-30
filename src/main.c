/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:46:23 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 22:38:23 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_cub_data	cub_data;

	if (args_checker(argc, argv))
		return (ERR);
	initialize_cub_data(&cub_data, argv[1]);
	init_cub_data(&cub_data);
	mlx_put_image_to_window(cub_data.mlx, cub_data.win,
		cub_data.texinfo.east.img, 0, 0);
	mlx_loop(cub_data.mlx);
	// system("leaks -atExit -- ./cub3D");
	return (0);
}
