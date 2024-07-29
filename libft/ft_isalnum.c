/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:06:15 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:06:15 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int main()
// {
// 	ft_putnbr_fd(ft_isalnum('1'), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isalnum('A'), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isalnum('F'), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isalnum('1'), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isalnum('5'), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isalnum('x'), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_isalnum('\n'), 1);
// 	ft_putchar_fd('\n', 1);
// }