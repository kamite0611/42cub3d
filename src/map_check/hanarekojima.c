/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanarekojima.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/08 17:01:25 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_round_player(char **temp_map)
{
	int			i;
	size_t		j;
	char		round[8];
printf("eee\n");
	i = -1;
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (ft_strchr("NEWS", temp_map[i][j]))
			{
				round[0] = temp_map[i - 1][j - 1];
				round[1] = temp_map[i - 1][j];
				round[2] = temp_map[i - 1][j + 1];
				round[3] = temp_map[i][j - 1];
				round[4] = temp_map[i][j + 1];
				round[5] = temp_map[i + 1][j - 1];
				round[6] = temp_map[i + 1][j];
				round[7] = temp_map[i + 1][j + 1];
				if (ft_strchr(round, ' ') || ft_strchr(round, '$'))
					return (free_exit(NULL, err_msg(ERR_PLAYER, 1)), 1);
			}
		}
	}
	return (0);
}

bool	validate_round_space(char **temp_map)
{
	int			i;
	size_t		j;
	char		round[8];
printf("ddd\n");
	i = -1;
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == ' ')
			{
				round[0] = temp_map[i - 1][j - 1];
				round[1] = temp_map[i - 1][j];
				round[2] = temp_map[i - 1][j + 1];
				round[3] = temp_map[i][j - 1];
				round[4] = temp_map[i][j + 1];
				round[5] = temp_map[i + 1][j - 1];
				round[6] = temp_map[i + 1][j];
				round[7] = temp_map[i + 1][j + 1];
				if (ft_strchr(round, '0'))
					return (free_exit(NULL, err_msg(ERR_SPACE, 1)), 1);
			}
		}
	}
	return (0);
}

bool	validate_round_zero(char **temp_map)
{
	int			i;
	size_t		j;
	char		round[8];
printf("ggg\n");
	i = -1;
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == '0')
			{
				round[0] = temp_map[i - 1][j - 1];
				round[1] = temp_map[i - 1][j];
				round[2] = temp_map[i - 1][j + 1];
				round[3] = temp_map[i][j - 1];
				round[4] = temp_map[i][j + 1];
				round[5] = temp_map[i + 1][j - 1];
				round[6] = temp_map[i + 1][j];
				round[7] = temp_map[i + 1][j + 1];
				if (ft_strchr(round, '$') || ft_strchr(round, ' '))
					return (free_exit(NULL, err_msg(ERR_ZERO, 1)), 1);
			}
		}
	}
	return (0);
}
