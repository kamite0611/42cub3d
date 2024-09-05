/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanarekojima.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/06 08:35:58 by mnakashi         ###   ########.fr       */
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
					return (free_exit(NULL, err_msg(ERR_MAP, 1)), 1);
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
					return (free_exit(NULL, err_msg(ERR_MAP, 1)), 1);
			}
		}
	}
	return (0);
}

static bool	is_empty(const char **map, int y, int x)
{
	int	map_height;

	map_height = 0;
	while (map[map_height])
		map_height++;
	if (x < 0 || y < 0)
		return (false);
	if (map_height <= y || (int)ft_strlen(map[y]) <= x)
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
					|| i == 0 || j == 0 || !map[i - 1][j - 1] || !map[i - 1][j]
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
