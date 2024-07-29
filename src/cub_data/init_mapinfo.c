/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:00 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 01:25:17 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int parse_line(char *line, t_mapinfo *mapinfo)
{
	if(ft_strncmp(line, "NO", 2) == 0){
		mapinfo->no_path = ft_strtrim_both(line, "NO ", "\n");
	}else if(ft_strncmp(line, "SO", 2) == 0){
		mapinfo->so_path = ft_strtrim_both(line, "SO ", "\n");
	}else if(ft_strncmp(line, "WE", 2) == 0){
		mapinfo->we_path = ft_strtrim_both(line, "WE ", "\n");
	}else if(ft_strncmp(line, "EA", 2) == 0){
		mapinfo->ea_path = ft_strtrim_both(line, "EA ", "\n");
	}
	return SUCCESS;
}

/**
 * ファイルの列数を mapinfo に入れる
 * - mapinfo.line_count	ファイル列数 (int)
 */
static int parse_file(t_mapinfo *mapinfo)
{
	char	*line;
	int fd = open(mapinfo->path, O_RDONLY);

	if (fd < 0)
		return err_msg("File not found.", ERR);

	line = get_next_line(fd);
	while (line != NULL)
	{
		mapinfo->line_count++;
		parse_line(line, mapinfo);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return SUCCESS;
}

/**
 * ファイル情報を
 */

void init_mapinfo(t_cub_data *cubdata)
{
	if(parse_file(&cubdata->mapinfo))
		free_exit(cubdata, ERR);

	put_mapinfo(&cubdata->mapinfo);
}
