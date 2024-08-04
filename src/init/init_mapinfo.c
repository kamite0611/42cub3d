/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:00 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 17:18:00 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Map情報をファイルから取得する
 */

static void	put_map_direct(char **line, t_mapinfo *mapinfo)
{
	if (ft_strcmp(line[0], "NO") == 0)
		mapinfo->no_path = ft_strtrim(ft_strdup(line[1]), "\n");
	else if (ft_strcmp(line[0], "SO") == 0)
		mapinfo->so_path = ft_strtrim(ft_strdup(line[1]), "\n");
	else if (ft_strcmp(line[0], "WE") == 0)
		mapinfo->we_path = ft_strtrim(ft_strdup(line[1]), "\n");
	else if (ft_strcmp(line[0], "EA") == 0)
		mapinfo->ea_path = ft_strtrim(ft_strdup(line[1]), "\n");
}

static void	put_map_rgb(char **line, t_mapinfo *mapinfo)
{
	char	**colors;

	colors = ft_split(ft_strtrim(line[1], "\n"), ',');
	if (ft_strcmp(line[0], "C") == 0)
	{
		mapinfo->ceiling_rgb[0] = ft_atoi(colors[0]);
		mapinfo->ceiling_rgb[1] = ft_atoi(colors[1]);
		mapinfo->ceiling_rgb[2] = ft_atoi(colors[2]);
	}
	else if (ft_strcmp(line[0], "F") == 0)
	{
		mapinfo->floor_rgb[0] = ft_atoi(colors[0]);
		mapinfo->floor_rgb[1] = ft_atoi(colors[1]);
		mapinfo->floor_rgb[2] = ft_atoi(colors[2]);
	}
	free_tab((void **)colors);
}

void	put_mapinfo(char *line, int count, t_mapinfo *mapinfo, char **map)
{
	char	**temp_line;

	if (count < 6)
	{
		temp_line = ft_split(line, ' ');
		if (count < 4)
			put_map_direct(temp_line, mapinfo);
		else if (count < 6)
			put_map_rgb(temp_line, mapinfo);
		free_tab((void **)temp_line);
	}
	else
		map[count - 6] = ft_strtrim(ft_strdup(line), "\n");
	free(line);
}

int	init_mapinfo(t_game *game, t_mapinfo *mapinfo, t_temp *temp)
{
	char	**map;
	int		fd;
	int		count;
	char	*line;

	fd = open(temp->map_path, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	count = 0;
	game->mapinfo.line_count = temp->map_count;
	game->player.direction = temp->player_direction;
	game->player.map_x = temp->player_mapx;
	game->player.map_y = temp->player_mapy;
	map = (char **)ft_calloc(sizeof(char *), (temp->map_count + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (ft_strcmp(line, "\n") == 0)
			continue ;
		put_mapinfo(line, count++, mapinfo, map);
	}
	mapinfo->map = map;
	return (close(fd), SUCCESS);
}

int	initialize_mapinfo(t_mapinfo *mapinfo, char *map_path)
{
	mapinfo->path = map_path;
	mapinfo->line_count = 0;
	mapinfo->no_path = NULL;
	mapinfo->so_path = NULL;
	mapinfo->we_path = NULL;
	mapinfo->ea_path = NULL;
	mapinfo->floor_rgb[0] = 0;
	mapinfo->floor_rgb[1] = 0;
	mapinfo->floor_rgb[2] = 0;
	mapinfo->ceiling_rgb[0] = 0;
	mapinfo->ceiling_rgb[1] = 0;
	mapinfo->ceiling_rgb[2] = 0;
	return (SUCCESS);
}

// mapinfo->no_path = ft_strdup("textures/bookshelf.xpm");
	// mapinfo->so_path = ft_strdup("textures/bookshelf.xpm");
	// mapinfo->we_path = ft_strdup("textures/bookshelf.xpm");
	// mapinfo->ea_path = ft_strdup("textures/bookshelf.xpm");
	//mapinfo->line_count = 22;
	// mapinfo->floor_rgb[0] = 53;
	// mapinfo->floor_rgb[1] = 41;
	// mapinfo->floor_rgb[2] = 34;
	// mapinfo->ceiling_rgb[0] = 45;
	// mapinfo->ceiling_rgb[1] = 33;
	// mapinfo->ceiling_rgb[2] = 27;
	// map = malloc(sizeof(char *) * 14);
	// map[0] = ft_strdup("111111111111111");
	// map[1] = ft_strdup("111111000111111");
	// map[2] = ft_strdup("111110000011111");
	// map[3] = ft_strdup("1111000N0001111");
	// map[4] = ft_strdup("111000000000111");
	// map[5] = ft_strdup("110000000000011");
	// map[6] = ft_strdup("100001111100001");
	// map[7] = ft_strdup("110000111000011");
	// map[8] = ft_strdup("111000010000111");
	// map[9] = ft_strdup("111100000001111");
	// map[10] = ft_strdup("111110000011111");
	// map[11] = ft_strdup("111111000111111");
	// map[12] = ft_strdup("111111111111111");
	// map[13] = NULL;
