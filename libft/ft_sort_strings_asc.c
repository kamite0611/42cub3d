/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strings_asc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:34:13 by akamite           #+#    #+#             */
/*   Updated: 2024/06/12 19:57:28 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_strings_asc(char **str_arr)
{
	int		i;
	int		ii;
	char	*tmp;

	i = 0;
	ii = 0;
	while (str_arr[i])
	{
		ii = 0;
		while (str_arr[i + ii])
		{
			if (ft_strcmp(str_arr[i], str_arr[i + ii]) > 0)
			{
				tmp = str_arr[i];
				str_arr[i] = str_arr[i + ii];
				str_arr[i + ii] = tmp;
			}
			ii++;
		}
		i++;
	}
	return (str_arr);
}

// int	main(void)
// {
// 	char	*arr[] = {"apple", "orange", "banana", "pear", "grape", 0};
// 	int		i;

// 	i = 0;
// 	printf("Before sorting:\n");
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// 	ft_sort_strings_asc(arr);
// 	i = 0;
// 	printf("After sorting:\n");
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
