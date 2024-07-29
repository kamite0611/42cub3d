/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:06:47 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:06:47 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

// int	main()
// {
// 	ft_putnbr_fd(ft_isprint(45), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isprint(19), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isprint(127), 1);
// 	ft_putchar_fd('\n', 1);
// }