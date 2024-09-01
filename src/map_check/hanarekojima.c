/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanarekojima.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/01 15:53:04 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_empty(const char **map, int y, int x)
{
	int	mapHeight;

	mapHeight = 0;
	while (map[mapHeight])
		mapHeight++;
	if (x < 0 || y < 0)
		return (false);
	if (mapHeight <= y || (int)ft_strlen(map[y]) <= x)
		return (true);
	return (map[y][x] == ' ');
}

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
			if (ft_strchr("NEWS", map[i][j]) != NULL && (i
					+ 1 == mapinfo->map_height || j + 1 == ft_strlen(map[i])
					|| i == 6 || j == 0 || !map[i - 1][j - 1] || !map[i - 1][j]
					|| !map[i + 1][j] || !map[i + 1][j - 1] || !map[i][j + 1]
					|| !map[i + 1][j + 1] || !map[i][j - 1] || !map[i - 1][j
					+ 1] || map[i][j - 1] == ' ' || map[i][j + 1] == ' '
					|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || map[i
					- 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ' || map[i
					+ 1][j - 1] == ' ' || map[i + 1][j + 1] == ' '))
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

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((mapinfo->map[i][j] == '0') && (is_empty(map, i - 1, j - 1)
					|| is_empty(map, i - 1, j) || is_empty(map, i - 1, j + 1)
					|| is_empty(map, i, j - 1) || is_empty(map, i, j + 1)
					|| is_empty(map, i + 1, j - 1) || is_empty(map, i + 1, j)
					|| is_empty(map, i + 1, j + 1)))
				return (free_exit(game, err_msg(ERR_MAP, 1)), 1);
		}
	}
	return (0);
}
