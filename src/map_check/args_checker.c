/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/06 08:41:26 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	matomete_free(char **tab, char **spline, char *line)
{
	free_tab((void **)tab);
	free_tab((void **)spline);
	free(line);
	free_exit(NULL, err_msg(ERR_MAP, 1));
}

bool	check_rgb(char *c_line, char **spline, char *line)
{
	char	**colors;
	int		i;
	size_t	j;
	char	*trimedline;

	trimedline = ft_strtrim(c_line, "\n");
	colors = ft_split(trimedline, ',');
	free(trimedline);
	i = -1;
	while (colors[++i])
	{
		if (i > 2)
			return (matomete_free(colors, spline, line), 1);
		j = -1;
		while (++j < ft_strlen(colors[i]))
		{
			if (!ft_isdigit(colors[i][j]) || ft_atoi(colors[i]) > 255)
				return (matomete_free(colors, spline, line), 1);
		}
	}
	if (i < 2)
		return (matomete_free(colors, spline, line), 1);
	return (free_tab((void **)colors), SUCCESS);
}

bool	check_dirgb(char **spline, char *line, int i)
{
	static char	*dirgb[6] = {"NO", "WE", "SO", "EA", "C", "F"};
	static bool	dirgb_fl[6] = {false};

	if (!spline || !spline[0])
	{
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
				&& !spline[2] && ((i < 4 && ft_strnstr(spline[1], "text", 4))
					|| (i >= 4 && check_rgb(spline[1], spline, line) == 0)))
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
		return (check_dirgb(ft_split(line, ' '), line, 0));
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

#include <stdio.h>
void	validate_map(t_temp *temp)
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
			ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0 ||
			ft_strcmp(line, "\n") == 0)
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
	if (ft_strchr(temp_map[temp->map_count - 6], '0'))
		printf("aaa\n");//free_exit(NULL, err_msg(ERR_MSG, 1)); //for bottom include '0'
	if (validate_round_player(temp_map) == 0)
		printf("bbb\n");
	if (validate_round_space(temp_map) == 0)
		printf("ccc\n");
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
		if (count > 5 && ft_strcmp(line, "\n") == 0) //for bottom hanarekojima
			return (close(fd), free_exit(NULL, err_msg("$$$", 1)), 1);
		if (count > 5 && temp->max_width < ft_strlen(line))
			temp->max_width = ft_strlen(line);
		free(line);
	}
	if (count < 6 || temp->player_flag == false)
		free_exit(NULL, err_msg(ERR_MAP, 1));
	temp->map_count = count;
	printf("%zu\n", temp->max_width);
	validate_map(temp);
	return (close(fd), SUCCESS);
}
