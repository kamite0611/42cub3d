/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:08:55 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 02:01:19 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	err_msg(char *msg, int status)
{
	if (msg)
		ft_putstr_fd(msg, status);
	ft_putstr_fd("\n", status);
	return (status);
}
