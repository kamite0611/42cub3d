/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:12:22 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:31:32 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

char	*ft_strdup(const char *src)
{
	const char	*src_ptr = src;
	size_t		len;
	char		*duplicate;

	while (*src_ptr != '\0')
	{
		src_ptr++;
	}
	len = src_ptr - src;
	duplicate = (char *)malloc((len + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_strcpy(duplicate, src);
	return (duplicate);
}

// int	main()
// {
// 	char	str[] = "asdfghjkl";
// 	char	str1[] = "xcvbnm";
// 	char	str2[] = "345678uhj";
// 	ft_putendl_fd(ft_strdup(str), 1);
// 	ft_putendl_fd(ft_strdup(str1), 1);
// 	ft_putendl_fd(ft_strdup(str2), 1);
// }