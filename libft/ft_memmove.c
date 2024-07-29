/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:19:38 by mnakashi          #+#    #+#             */
/*   Updated: 2024/06/13 22:47:48 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (dest <= src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}

// #include <stdio.h>
// int main(void){
// 	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
// 	char buff[0xF0];
// 	char *p1;
// 	char *p2;
// 	int n = 100;
// 	p1 = ft_memmove(buff,src, n);
// 	printf("mymemmove = %s\n",p1);
// 	p2 = memmove(buff,src, n);
// 	printf("memmove   = %s\n",p2);
// 	return (0);
// }