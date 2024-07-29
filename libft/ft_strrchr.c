/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:13:15 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:10 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*string)
	{
		if (*string == (unsigned char)c)
			ptr = (char *)string;
		string++;
	}
	if (c == 0)
		return ((char *)string);
	return (ptr);
}

// int	main()
// {
// 	char	str[] = "asdfghj";
// 	char	c = 'd';
// 	printf("%s",ft_strrchr(str, c));
// }