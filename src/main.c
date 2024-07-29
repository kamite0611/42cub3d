/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:46:23 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 23:27:18 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char *argv[])
{
	t_cub_data cub_data;

	(void)argv;
	if (argc != 2)
		return (err_msg(ERR_USAGE, 1));
	initialize_cub_data(&cub_data, argv[2]);
	init_cub_data(&cub_data);

	mlx_loop(cub_data.mlx);
	return 0;
}
