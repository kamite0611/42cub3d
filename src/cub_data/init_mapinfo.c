/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:16:00 by akamite           #+#    #+#             */
/*   Updated: 2024/07/30 00:38:52 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int set_content(t_mapinfo *mapinfo)
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
		result = ft_strjoin(mapinfo->content, line);
		free(line);
		free(mapinfo->content);
		mapinfo->content = result;
		line = get_next_line(fd);
	}
	close(fd);
	return SUCCESS;
}

static void alloc_mapinfo(t_mapinfo *mapinfo)
{
	(void)mapinfo;
}

void init_mapinfo(t_cub_data *cubdata)
{
	if(set_content(&cubdata->mapinfo))
		free_exit(cubdata, ERR);

	printf("%s\n", cubdata->mapinfo.content);
	alloc_mapinfo(&cubdata->mapinfo);

}
