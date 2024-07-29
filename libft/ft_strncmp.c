/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:13:06 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:02 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (size && *ptr1 && *ptr1 == *ptr2)
	{
		++ptr1;
		++ptr2;
		--size;
	}
	if (size)
		return (*ptr1 - *ptr2);
	else
		return (0);
}

// int	main()
// {
// 	char	str[] = "sdfghjk";
// 	char	str1[] = "cvbnm";
// 	printf("%d",ft_strncmp(str, str1, 5));
// 	write(1,"\n", 1);
// }
