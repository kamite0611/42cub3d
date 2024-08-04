/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/08/04 16:22:31 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
	return ;
}

bool	check_rgb(char *line)
{
	char	**colors;
	size_t	color_len;
	int		i;
	size_t	j;

	colors = ft_split(ft_strtrim(line, "\n"), ',');
	i = -1;
	j = -1;
	while (colors[++i])
	{
		if (i > 3)
			free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1));
		color_len = ft_strlen(colors[i]);
		if (color_len == 0 || color_len > 3)
			free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1));
		while (++j < color_len)
		{
			if (!ft_isdigit(colors[i][j]) || ft_atoi(colors[i]) > 255)
				free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1));
		}
	}
	if (i < 2)
		free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1));
	return (free_lines(colors), SUCCESS);
}

bool	check_dirgb(char **line)
{
	static char	*dirgb[6] = {"NO", "WE", "SO", "EA", "C", "F"};
	static bool	dirgb_fl[6] = {false};
	int			i;

	if (!line || !line[0])
		return (free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1)), ERROR);
	if (line[0])
	{
		i = -1;
		while (++i < 6)
		{
			if (!ft_strcmp(line[0], dirgb[i]) && !dirgb_fl[i] && line[1]
				&& ((i < 4 && open(ft_strtrim(line[1], "\n"), 644) >= 0)
					|| (i >= 4 && check_rgb(line[1]) == SUCCESS)) && !line[2])
			{
				dirgb_fl[i] = true;
				return (free_lines(line), SUCCESS);
			}
		}
	}
	return (free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1)), ERROR);
}

bool	read_map(char *line, int count, t_temp *temp, size_t line_len)
{
	size_t		i;

	if (count <= 5)
		return (check_dirgb(ft_split(line, ' ')));
	i = -1;
	while (++i < line_len)
	{
		if (!ft_strchr("NEWS01\n ", line[i]))
			return (free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1)), ERROR);
		if (ft_strchr("NEWS", line[i]))
		{
			if (temp->player_flag == true)
				free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1));
			temp->player_direction = line[i];
			temp->player_mapx = i;
			temp->player_mapy = count - 6;
			temp->player_flag = true;
		}
	}
	return (SUCCESS);
}

int	args_checker(int argc, char *argv[], t_temp *temp)
{
	int		fd;
	int		count;
	char	*line;

	if (argc != 2 || ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0)
		free_exit(NULL, err_msg(ERR_USAGE, 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free_exit(NULL, err_msg(ERR_ARGMAP, 1)), close(fd), ERROR);
	ft_strlcpy(temp->map_path, argv[1], 4095);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (ft_strcmp(line, "\n") == 0)
			continue ;
		read_map(line, count++, temp, ft_strlen(line));
	}
	if (count < 6 || temp->player_flag == false)
		free_exit(NULL, err_msg(ERR_MAP_CONTENT, 1));
	temp->map_count = count;
	return (close(fd), SUCCESS);
}
