/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:08:55 by akamite           #+#    #+#             */
/*   Updated: 2024/09/01 16:21:21 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *msg, int status)
{
	ft_putstr_fd("Error\n", status);
	if (msg)
		ft_putstr_fd(msg, status);
	ft_putstr_fd("\n", status);
	return (status);
}
