/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/08/03 22:39:10 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <limits.h> //For PATH_MAX

/**
 * コマンドライン引数が正しいかチェックする
 * - コマンドライン引数の数が正しいか
 * - ファイルパスが正しいか
 * - ファイルの内容が正しいか
 */

//不要? !(ft_strnstr(argv[1], "./maps/", 7) || ft_strnstr(argv[1], "maps/", 5)))

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
			free_exit(NULL, err_msg(ERR_MSG, 1));
		color_len = ft_strlen(colors[i]);
		if (color_len == 0 || color_len > 3)
			free_exit(NULL, err_msg(ERR_USAGE, 1));
		while (++j < color_len)
		{
			if (!ft_isdigit(colors[i][j]) || ft_atoi(colors[i]) > 255)
				free_exit(NULL, err_msg(ERR_USAGE, 1));
		}
	}
	if (i < 2)
		free_exit(NULL, err_msg(ERR_USAGE, 1));
	// free(colors)
	return (SUCCESS);
}

bool	check_dirgb(char **line)
{
	static char	*dirgb[6] = {"NO", "WE", "SO", "EA", "C", "F"};
	static bool	dirgb_flag[6] = {false};

	if (!dirgb_flag[0] && !ft_strcmp(line[0], dirgb[0]) && line[1]
		&& ft_strcmp(line[1] + ft_strlen(line[1]) - 5, ".xpm\n") == 0)
		dirgb_flag[0] = true;
	else if (!dirgb_flag[1] && !ft_strcmp(line[0], dirgb[1]) && line[1]
		&& ft_strcmp(line[1] + ft_strlen(line[1]) - 5, ".xpm\n") == 0)
		dirgb_flag[1] = true;
	else if (!dirgb_flag[2] && !ft_strcmp(line[0], dirgb[2]) && line[1]
		&& ft_strcmp(line[1] + ft_strlen(line[1]) - 5, ".xpm\n") == 0)
		dirgb_flag[2] = true;
	else if (!dirgb_flag[3] && !ft_strcmp(line[0], dirgb[3]) && line[1]
		&& ft_strcmp(line[1] + ft_strlen(line[1]) - 5, ".xpm\n") == 0)
		dirgb_flag[3] = true;
	else if (!dirgb_flag[4] && !ft_strcmp(line[0], dirgb[4]) && line[1]
		&& check_rgb(line[1]) == SUCCESS)
		dirgb_flag[4] = true;
	else if (!dirgb_flag[5] && !ft_strcmp(line[0], dirgb[5]) && line[1]
		&& check_rgb(line[1]) == SUCCESS)
		dirgb_flag[5] = true;
	else
		free_exit(NULL, err_msg(ERR_MSG, 1));
	return (SUCCESS);
}

int	args_checker(int argc, char *argv[], t_temp *temp)
{
	size_t	map_name_len;
	int		fd;
	int		count;
	bool	player_flag;
	char	*line;
	char	**temp_line;
	size_t	line_len;
	size_t	i;

	if (argc != 2)
		free_exit(NULL, err_msg(ERR_USAGE, 1));
	/** @TODO add argv checker */
	// check map path
	map_name_len = ft_strlen(argv[1]);
	if (map_name_len == 0 || ft_strcmp(argv[1] + map_name_len - 4, ".cub") != 0
		|| !(ft_strnstr(argv[1], "./maps/", 7) || ft_strnstr(argv[1], "maps/",
				5)))
	{
		free_exit(NULL, err_msg(ERR_MSG, 1));
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free_exit(NULL, err_msg(ERR_MSG, 1));
	}
	ft_strlcpy(temp->map_path, argv[1], 4095);
	count = 0;
	player_flag = false;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		else if (ft_strcmp(line, "\n") == 0)
		{
			continue ;
		}
		count++;
		if (count <= 6)
		{
			temp_line = ft_split(line, ' ');
			if (temp_line[0] && check_dirgb(temp_line) == SUCCESS)
			{
				continue ; // free(temp_line)
			}
		}
		else if (count > 6)
		{
			line_len = ft_strlen(line);
			i = -1;
			while (++i < line_len)
			{
				if (line[i] == '0' || line[i] == '1' || line[i] == ' '
					|| line[i] == '\n')
				{
					continue ;
				}
				else if (ft_strchr("NEWS", line[i]))
				{
					if (player_flag == true)
					{
						free_exit(NULL, err_msg(ERR_MSG, 1));
					}
					temp->player_direction = line[i];
					temp->player_mapx = i;
					temp->player_mapy = count - 7;
					player_flag = true;
				}
				else
				{
					free_exit(NULL, err_msg(ERR_MSG, 1));
				}
			}
		}
		// free(line);
	}
	if (count < 7 || player_flag == false)
		free_exit(NULL, err_msg(ERR_MSG, 1));
	temp->map_count = count;
	return (SUCCESS);
}
