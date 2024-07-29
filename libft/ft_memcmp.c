/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:11:08 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:36:18 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)buf1;
	str2 = (unsigned char *)buf2;
	while (count && *str1 == *str2)
	{
		++str1;
		++str2;
		--count;
	}
	if (count)
		return (*str1 - *str2);
	else
		return (0);
}

// #include <stdio.h>
// int main(void){
// 	unsigned char s1[] = "abcdefgh";
// 	unsigned char s2[] = "abcdefgh";
// 	int c =-120;
// 	s1[2]=-120;
// 	printf("memcmp   = %d\n",ft_memcmp(s1,s2,8));
// 	printf("mymemcmp = %d\n",memcmp(s1,s2,8));
// 	return 0;
// }