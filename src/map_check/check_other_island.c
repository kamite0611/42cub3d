/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other_island.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:47:52 by akamite           #+#    #+#             */
/*   Updated: 2024/08/28 19:34:35 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**strarr_dup(char **strarr)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)ft_calloc(sizeof(char *), strarr_size(strarr) + 1);
	if (!result)
		return (NULL);
	while (strarr[i])
	{
		result[i] = ft_strdup(strarr[i]);
		if (!result[i])
			return (free_tab((void **)result), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}

static void	fill_island(char **map, int y, int x)
{
	if (y < 0 || x < 0 || !map[y] || ft_strlen(map[y]) < (size_t)x + 1)
		return ;
	if (map[y][x] == FILLED_C || map[y][x] == EMPTY_C)
		return ;
	map[y][x] = FILLED_C;
	fill_island(map, y + 1, x);
	fill_island(map, y, x + 1);
	fill_island(map, y - 1, x);
	fill_island(map, y, x - 1);
}

static void	check_filled_map(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != EMPTY_C && map[i][j] != FILLED_C)
			{
				free_tab((void **)map);
				free_exit(game, err_msg("Remote islands found.", ERROR));
			}
			j++;
		}
		i++;
	}
}

void	check_other_island(t_game *game)
{
	char	**cpy_map;

	cpy_map = strarr_dup(game->mapinfo.map);
	if (!cpy_map)
		free_exit(game, ERROR);
	fill_island(cpy_map, (int)game->player.map_y, (int)game->player.map_x);
	check_filled_map(cpy_map, game);
	free_tab((void **)cpy_map);
}
