/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:11:03 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:30:48 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	c = (unsigned char)c;
	while (count && *ptr != c)
	{
		++ptr;
		--count;
	}
	if (count)
		return ((void *)ptr);
	else
		return (NULL);
}

// #include <stdio.h>
// int main(void){
// 	unsigned char s[] = "abcdefgh";
// 	char *p1;
// 	char *p2;
// 	int c =-120;
// 	int n = 8;
// 	s[2]=-120;		//文字列sの'c'を-120に変更
// 	p1 = ft_memchr(s,c, n);
// 	printf("memchr   = %s\n",p1);
// 	p2 = ft_memchr(s,c, n);
// 	printf("mymemchr = %s\n",p2);
// 	return 0;
// }