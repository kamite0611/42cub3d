/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanarekojima.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/01 00:25:57 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	vrp(t_mapinfo *mapinfo, t_game *game)
{
	int			i;
	size_t		j;
	const char	**map = (const char **)mapinfo->map;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NEWS", map[i][j]) != NULL
				&& (i + 1 == mapinfo->map_height || j + 1 == ft_strlen(map[i])
					|| i == 6 || j == 0 || !map[i - 1][j - 1] || !map[i - 1][j]
					|| !map[i + 1][j] || !map[i + 1][j - 1] || !map[i][j + 1]
					|| !map[i + 1][j + 1] || !map[i][j - 1]
					|| !map[i - 1][j + 1] || map[i][j - 1] == ' '
					|| map[i][j + 1] == ' ' || map[i + 1][j] == ' '
					|| map[i - 1][j] == ' ' || map[i - 1][j - 1] == ' '
					|| map[i - 1][j + 1] == ' ' || map[i + 1][j - 1] == ' '
					|| map[i + 1][j + 1] == ' '))
				return (free_exit(game, err_msg(ERR_MAP, 1)), 1);
		}
	}
	return (0);
}

bool	vrs(t_mapinfo *mapinfo, t_game *game)
{
	int			i;
	size_t		j;
	const char	**map = (const char **)mapinfo->map;
	const int	h = mapinfo->map_height;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((mapinfo->map[i][j] == ' ')
				&& ((i > 0 && j > 0 && map[i - 1][j - 1] == '0')
					|| (i > 0 && map[i - 1][j] == '0')
					|| (i > 0 && map[i - 1][j + 1] && map[i - 1][j + 1] == '0')
					|| (j > 0 && map[i][j - 1] && map[i][j - 1] == '0')
					|| (map[i][j + 1] && map[i][j + 1] == '0')
					|| (i < h - 1 && j > 0 && ft_strlen(map[i + 1]) > j
						&& (map[i + 1][j - 1] == '0' || map[i + 1][j] == '0'
							|| map[i + 1][j + 1] == '0'))))
				return (free_exit(game, err_msg(ERR_MAP, 1)), 1);
		}
	}
	return (0);
}
