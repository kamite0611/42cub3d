/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:12:01 by mnakashi          #+#    #+#             */
/*   Updated: 2024/06/14 10:08:09 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	new = ft_calloc(len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s1, len);
	return (new);
}

//memmmove→strcpy
