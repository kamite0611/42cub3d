/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:12:01 by mnakashi          #+#    #+#             */
/*   Updated: 2024/04/15 21:31:25 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		word_index;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	result = (char **) ft_calloc(sizeof(char *), count_words(str, c) + 1);
	if (!result)
		return (NULL);
	word_index = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!str[i])
			break ;
		len = wlen(str + i, c);
		result[word_index] = ft_substr(str, i, len);
		if (!result[word_index++])
			return (free_all(result));
		i += len;
	}
	return (result);
}

// int	main()
// {
// 	char	str[] = "";
// 	char	c = 19;
// 	char	**spt = ft_split(str, c);
// 	int	i = 0;
// 	if(spt[i] == NULL){printf("yatta");}
// 	while (spt[i] != 0)
// 	{
// 		ft_putstr_fd(spt[i], 1);
// 		i++;
// 	}
// 	ft_putchar_fd('\n', 1);
// }