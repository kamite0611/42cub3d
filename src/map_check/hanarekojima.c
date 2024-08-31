/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanarekojima.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/08/31 18:17:15 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

bool	validate_round_player(t_mapinfo *mapinfo, t_game *game)
{
	int			i;
	size_t		j;
	const char	**map = (const char **)mapinfo->map;
printf("hanarekojima\n");
	i = 5;
	while (map[++i])
	{
		j = -1;
		while (map[++j])
		{
			if ((ft_strchr("NEWS", mapinfo->map[i][j]) != NULL)
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

// bool	validate_round_space(t_mapinfo *mapinfo, t_game *game)　//around 0
// {
// 	int	i;
// 	int	j;

// 	i = 4;
// 	while (mapinfo->map[++i])
// 	{
// 		j = -1;
// 		while (mapinfo->map[++j])
// 		{
// 			if ((mapinfo->map[i][j] == ' ')
// 			&& (mapinfo->map[i][j-1] == '0' || mapinfo->map[i][j+1] == '0' || mapinfo->map[i+1][j] == '0' || mapinfo->map[i-1][j] == '0')
// 			&& (mapinfo->map[i-1][j-1] == '0' || mapinfo->map[i-1][j+1] == '0' || mapinfo->map[i+1][j-1] == '0' || mapinfo->map[i+1][j+1] == '0'))
// 				return (free_exit(game, err_msg(ERR_MAP, 1)), 1);
// 		}
// 	}
// 	return (0);
// }

// bool	validate_round_zero(t_mapinfo *mapinfo, t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 4; //around 
// 	while (mapinfo->map[++i])
// 	{
// 		j = -1;
// 		while (mapinfo->map[++j])
// 		{
// 			if ((mapinfo->map[i][j] == ' ')
// 			&& (mapinfo->map[i][j-1] == '0' || mapinfo->map[i][j+1] == '0' || mapinfo->map[i+1][j] == '0' || mapinfo->map[i-1][j] == '0')
// 			&& (mapinfo->map[i-1][j-1] == '0' || mapinfo->map[i-1][j+1] == '0' || mapinfo->map[i+1][j-1] == '0' || mapinfo->map[i+1][j+1] == '0'))
// 				return (free_exit(game, err_msg(ERR_MAP, 1)), 1);
// 		}
// 	}
// 	return (0);
// }
