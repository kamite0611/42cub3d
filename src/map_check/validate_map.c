/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:41:28 by akamite           #+#    #+#             */
/*   Updated: 2024/09/10 07:50:24 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_map(t_temp *temp)
{
	const int	fd = open(temp->map_path, O_RDONLY);
	char *line;

	char **temp_map = ft_calloc(sizeof(char *), temp->map_count - 3);
	int i = 0;
	size_t j;
	while (i < temp->map_count - 4)
	{
		temp_map[i] = ft_calloc(sizeof(char), temp->max_width + 2);
		j = 0;
		while (j < temp->max_width + 1)
			temp_map[i][j++] = '$';
		i++;
	}
	printf("[%s]\n", temp_map[0]);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
			ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0 ||
			ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0
			|| (i < 6 && ft_strcmp(line, "\n") == 0))
		{
			free(line);
			continue ;
		}
		j = 0;
		while (j < ft_strlen(line) - 1)
		{
			temp_map[i][j + 1] = line[j];
			j++;
		}
		printf("%d: [%s]\n", i, temp_map[i]);
		free(line);
		i++;
	}
	printf("[%s]\n", temp_map[i]);
	if (validate_round_player(temp_map) || validate_round_space(temp_map)
		|| validate_round_zero(temp_map))
		return (close(fd), matomete_free(NULL, temp_map, NULL, ERR_MSG), 1);
	return (close(fd), free_tab((void **)temp_map), 0);
}
