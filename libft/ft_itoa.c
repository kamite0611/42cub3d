/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:06:53 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:06:53 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	digits(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	natural_itoa(int nb, char *str)
{
	if (nb >= 10)
		natural_itoa(nb / 10, str - 1);
	*str = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		is_negative;

	is_negative = n < 0;
	if (is_negative)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = -n;
	}
	len = digits(n) + is_negative;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (is_negative)
		*result = '-';
	natural_itoa(n, result + len - 1);
	result[len] = '\0';
	return (result);
}

// int main()
// {
// 	int	i = 125;
// 	int	j = -814;
// 	int	min = -2147483648;
// 	int	max = 2147483647;
// 	ft_putstr_fd(ft_itoa(i), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(ft_itoa(j), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(ft_itoa(min), 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(ft_itoa(max), 1);
// 	ft_putchar_fd('\n', 1);
// }