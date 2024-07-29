/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:05:53 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:05:53 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	return ((c == ' ') || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (is_space(*str) == 1)
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -sign;
		}
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// int main()
// {
// 	char str1[] = "15613";
// 	char str2[] = "--1";
// 	char str3[] = "+15asd613";
// 	char str4[] = "-1561dase3";
// 	ft_putnbr_fd(ft_atoi(str1), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_atoi(str2), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_atoi(str3), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(ft_atoi(str4), 1);
// 	ft_putchar_fd('\n', 1);
// }