/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:37:18 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 22:10:52 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

// #include <stdio.h>
// int main(void){
// 	unsigned char s[] = "dfghj";
// 	char *p1;
// 	char *p2;
// 	unsigned char c[] ="sfdghjghj";
// 	int n = 8;
// 	p1 = ft_memcpy(s,c, n);
// 	printf("memcpy   = %s\n",p1);
// 	p2 = memcpy(s,c, n);
// 	printf("mymemcpy = %s\n",p2);
// 	return (0);
// }