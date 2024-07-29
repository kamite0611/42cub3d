/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:12:27 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:31:36 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, (s + i));
		++i;
	}
}

// void	ft_test(unsigned int i, char *str)
// 	{
// 		*str += i;
// 	}
// int	main()
// {
// 	char	str[] = "aBcDeF";
// 	ft_striteri(str, ft_test);
// 	ft_putendl_fd(str, 1);
// }