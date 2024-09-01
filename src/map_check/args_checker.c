/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/01 14:53:30 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	matomete_free(char **tab, char *line)
{
	free_tab((void **)tab);
	free(line);
	free_exit(NULL, err_msg(ERR_MAP, 1));
}

bool	check_rgb(char *line)
{
	char	**colors;
	int		i;
	size_t	j;
	char	*trimedline;

	trimedline = ft_strtrim(line, "\n");
	colors = ft_split(trimedline, ',');
	free(trimedline);
	i = -1;
	while (colors[++i])
	{
		if (i > 3)
			return (matomete_free(colors, line), 1);
		j = -1;
		while (++j < ft_strlen(colors[i]))
		{
			if (!ft_isdigit(colors[i][j]) || ft_atoi(colors[i]) > 255)
				return (free_tab((void **)colors), free(line), free_exit(NULL,
						err_msg(ERR_MAP, 1)), 1);
		}
	}
	if (i < 2)
		return (matomete_free(colors, line), 1);
	return (free_tab((void **)colors), SUCCESS);
}

bool	check_dirgb(char **spline, char *line)
{
	static char	*dirgb[6] = {"NO", "WE", "SO", "EA", "C", "F"};
	static bool	dirgb_fl[6] = {false};
	int			i;

	if (!spline || !spline[0]){
		if (spline)
			free_tab((void **)spline);
		return (free(line), free_exit(NULL, err_msg(ERR_MAP, 1)), 0);
	}
	if (spline[0])
	{
		i = -1;
		while (++i < 6)
		{
			if (!ft_strcmp(spline[0], dirgb[i]) && !dirgb_fl[i] && spline[1]
				&& ((i < 4 && ft_strnstr(spline[1], "text", 4)) || (i >= 4
						&& check_rgb(spline[1]) == SUCCESS)) && !spline[2])
			{
				dirgb_fl[i] = true;
				return (free_tab((void **)spline), 1);
			}
		}
	}
	return (free_tab((void **)spline), free(line), free_exit(NULL,
			err_msg(ERR_MAP, 1)), 0);
}

bool	read_map(char *line, int count, t_temp *temp, size_t line_len)
{
	size_t	i;

	if (count < 6)
		return (check_dirgb(ft_split(line, ' '), line));
	if (ft_strchr("NEWS0", line[0]) || ft_strchr("NEWS0 ", line[line_len - 2]))
		return (free(line), free_exit(NULL, err_msg(ERR_MAP, 1)), 0);
	i = -1;
	while (++i < line_len)
	{
		if (count == 6 && ft_strchr("NEWS0", line[i]))
			return (free(line), free_exit(NULL, err_msg(ERR_MAP, 1)), 0);
		if (ft_strchr("NEWS01\n ", line[i]) == NULL)
			return (free(line), free_exit(NULL, err_msg(ERR_MAP, 1)), 0);
		if (ft_strchr("NEWS", line[i]))
		{
			if (temp->player_flag == true)
				return (free(line), free_exit(NULL, err_msg(ERR_MAP, 1)), 0);
			temp->player_direction = line[i];
			temp->player_mapx = i;
			temp->player_mapy = count - 6;
			temp->player_flag = true;
		}
	}
	return (1);
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
		else if (ft_strcmp(line, "\n") != 0)
			count += read_map(line, count, temp, ft_strlen(line));
		free(line);
	}
	if (count < 6 || temp->player_flag == false)
		free_exit(NULL, err_msg(ERR_MAP, 1));
	temp->map_count = count;
	return (close(fd), SUCCESS);
}
