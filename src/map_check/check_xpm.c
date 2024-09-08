/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:41:28 by akamite           #+#    #+#             */
/*   Updated: 2024/09/08 15:25:18 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

static bool	is_xpm_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len - 5 < 0)
		return (false);
	if (path[len - 4] == '.' && path[len - 3] == 'x' && path[len - 2] == 'p'
		&& path[len - 1] == 'm')
		return (true);
	return (false);
}

bool	xpm_file_check(char *path)
{
	int	fd;

	if (is_dir(path))
		return (false);
	if (!is_xpm_file(path))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	check_textures_path(t_game *game)
{
	if (!xpm_file_check(game->mapinfo.no_path))
		return (false);
	if (!xpm_file_check(game->mapinfo.so_path))
		return (false);
	if (!xpm_file_check(game->mapinfo.we_path))
		return (false);
	if (!xpm_file_check(game->mapinfo.ea_path))
		return (false);
	return (true);
}
