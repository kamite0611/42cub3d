/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:11:30 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:31:10 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;
	char	*string;

	string = (char *)dest;
	i = 0;
	while (i < count)
	{
		string[i] = c;
		i++;
	}
	return (dest);
}

// int main()
// {
// 	char	str[] = "asdfghj";
// 	int	c = -120;
// 	ft_putstr_fd(ft_memset(str, c, 12), 1);
// 	ft_putchar_fd('\n', 1);
// }