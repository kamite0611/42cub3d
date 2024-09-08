/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/09/08 17:00:11 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//NOSOWEEACF not collect all case
//check Valgrind
//check joutyou na code
//norm
//confirm no=wall-bottom(need validate_round_zero(delete doll round zero case))
//confirm .cub pattern
//confirm a.cub.cub pattern
//hanarekojima3
//delete vrp vrs
//confirm print=debug temp=map
//delete (void)game delete init_mapinfo
#include <stdio.h>

void	matomete_free(char **tab, char **spline, char *line, char *message)
{
	if (tab)
		free_tab((void **)tab);
	if (spline)
		free_tab((void **)spline);
	if (line)
		free(line);
	free_exit(NULL, err_msg(message, 1));
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
			return (matomete_free(colors, spline, line, ERR_RGB), 1);
		j = -1;
		while (++j < ft_strlen(colors[i]))
		{
			if (!ft_isdigit(colors[i][j]) || j > 2 || ft_atoi(colors[i]) > 255)
				return (matomete_free(colors, spline, line, ERR_RGB), 1);
		}
	}
	if (i < 2)
		return (matomete_free(colors, spline, line, ERR_RGB), 1);
	return (free_tab((void **)colors), 0);
}

bool	check_dirgb(t_temp *temp, char **spline, char *line, int i)
{
	if (!spline || !spline[0])
		return (matomete_free(NULL, spline, line, ERR_DIRGB), 0);
	if (spline[0])
	{
		i = -1;
		while (++i < 6)
		{
			if (!ft_strcmp(spline[0], temp->dirgb[i]) && !temp->dirgb_flag[i]
				&& spline[1] && !spline[2] && ((i < 4 && xpm_nl_check(spline[1]))
					|| (i >= 4 && check_rgb(spline[1], spline, line) == 0)))
			{//tyottowakarinikui
				temp->dirgb_flag[i] = true;
				return (free_tab((void **)spline), 1);
			}
		}
	}
	return (matomete_free(NULL, spline, line, ERR_DIRECTION), 0);
}

bool	read_map(char *line, int count, t_temp *temp, size_t line_len)
{
	size_t	i;

	if (ft_strcmp(line, "\n") == 0 && count < 6)
		return (free(line), 0);
	else if (ft_strcmp(line, "\n") == 0 && count >= 6)
		return (free(line), 1);
	if (count < 6)
		return (check_dirgb(temp, ft_split(line, ' '), line, 0));
	// if (ft_strcmp(line, "\n") == 0)
	// 	return (free(line), 1);
	if (temp->max_width < ft_strlen(line)) //include nl
		temp->max_width = ft_strlen(line);
	if (ft_strchr("NEWS0", line[0]) || ft_strchr("NEWS0 ", line[line_len - 2]))
		return (matomete_free(NULL, NULL, line, ERR_MAP), 0);
	i = -1;
	while (++i < line_len)
	{
		if (count == 6 && ft_strchr("NEWS0", line[i]))
			return (matomete_free(NULL, NULL, line, ERR_MAP), 0);
		if (ft_strchr("NEWS01\n ", line[i]) == NULL) //ueto gappei
			return (matomete_free(NULL, NULL, line, ERR_MAP), 0);
		if (ft_strchr("NEWS", line[i]))
		{
			if (temp->player_flag == true)
				return (matomete_free(NULL, NULL, line, ERR_PLAYER), 0);
			temp->player_direction = line[i];
			temp->player_mapx = i;
			temp->player_mapy = count - 6;
			temp->player_flag = true;
		}
	}
	return (1);
}

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
		// if (count > 5 && temp->max_width < ft_strlen(line))
		// 	temp->max_width = ft_strlen(line);
		// free(line);
	}
	if (count < 6 || temp->player_flag == false)
		return (close(fd), free_exit(NULL, err_msg(ERR_MAP, 1)), ERROR);
	temp->map_count = count;
	printf("%zu\n", temp->max_width);
	count = -1;
	while (++count < 6)
		if (temp->dirgb[count] == false)
			return (close(fd), free_exit(NULL, err_msg(ERR_DIRGB, 1)), ERROR);
	return (close(fd), validate_map(temp), SUCCESS);
}
