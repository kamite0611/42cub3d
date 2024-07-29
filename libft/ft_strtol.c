/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:45:51 by akamite           #+#    #+#             */
/*   Updated: 2024/06/12 23:32:37 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>

static int	is_spacing(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	check_overflow(long a, long b, int neg)
{
	long	res;

	if (neg)
	{
		a = (-a);
		b = (-b);
	}
	res = a * 10;
	if (res / 10 != a)
	{
		errno = ERANGE;
		return (1);
	}
	res = a * 10 + b;
	if ((neg && res > 0) || (!neg && res < 0))
	{
		errno = ERANGE;
		return (1);
	}
	return (0);
}

static long	return_overflow(int neg)
{
	if (neg)
		return (LONG_MIN);
	return (LONG_MAX);
}

/**
 * Convert a string to a long integer.
 */
long	ft_strtol(const char *str, char **endptr)
{
	long	result;
	int		neg;

	result = 0;
	neg = 0;
	while (is_spacing(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (check_overflow(result, *str - '0', neg))
			return (return_overflow(neg));
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (endptr != 0)
		*endptr = (char *)str;
	if (neg)
		result = (-result);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*endptr;
// 	int		is_overflow;
// 	long	res;

// 	res = ft_strtol("-9223372036854775809", &endptr, &is_overflow);
// 	printf("%ld _ %s _ %d\n", res, endptr, is_overflow);
// }
