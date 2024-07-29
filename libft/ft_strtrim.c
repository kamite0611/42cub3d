/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:13:22 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:14 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}

// int	main()
// {
// 	printf("'bonjour' : '%s\n'", ft_strtrim("bonjour", " "));
// 	printf("'bonjour' : '%s'\n", ft_strtrim(" bonjour ", " "));
// 	printf("'onjour' : '%s'\n", ft_strtrim(" bonjour ", " b"));
// 	printf("'bonjour' : '%s'\n", ft_strtrim(" bonjour", " "));
// 	printf("'bonjour' : '%s'\n", ft_strtrim("bonjour ", " "));
// 	printf("'onjou' : '%s'\n", ft_strtrim("bonjour ", "br "));
// 	printf("'' : '%s'\n", ft_strtrim("", " "));
// 	printf("'test' : '%s'\n", ft_strtrim("test", ""));
// 	printf("'te st' : '%s'\n", ft_strtrim(" te st ", " "));
// 	printf("'' : '%s'\n", ft_strtrim(" b  ", "b "));
// }