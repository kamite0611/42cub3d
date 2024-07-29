/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:46:23 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 23:57:54 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char *argv[])
{
	t_cub_data cub_data;

	if(!args_checker(argc, argv))
		return ERR;

	initialize_cub_data(&cub_data, argv[2]);
	init_cub_data(&cub_data);

	mlx_loop(cub_data.mlx);
	return 0;
}
