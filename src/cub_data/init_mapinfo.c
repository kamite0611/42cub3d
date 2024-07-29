/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:00 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 00:57:43 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * ファイルの列数を mapinfo に入れる
 * - mapinfo.line_count	ファイル列数 (int)
 */
static int set_line_cont(t_mapinfo *mapinfo)
{
	char	*line;
	char	*result;
	int fd = open(mapinfo->path, O_RDONLY);

	if (fd < 0)
		return err_msg("File not found.", ERR);

	line = get_next_line(fd);
	while (line != NULL)
	{
		mapinfo->line_count++;
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
	if(set_line_cont(&cubdata->mapinfo))
		free_exit(cubdata, ERR);

}
