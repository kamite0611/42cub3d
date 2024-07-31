/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/08/01 06:39:53 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * コマンドライン引数が正しいかチェックする
 * - コマンドライン引数の数が正しいか
 * - ファイルパスが正しいか
 * - ファイルの内容が正しいか
 */
int	args_checker(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
		free_exit(NULL, err_msg(ERR_USAGE, ERROR));
	/** @TODO add argv checker */
	//check map path
	// size_t map_name_len = ft_strlen(argv[1]);
	// if !(map_name_len == 0) && (ft_strcmp(argv[1] + map_name_len - 4 == ".cub"))
	// 	&& (ft_strnstr(argv[1], "./maps/", 7) || ft_strnstr(argv[1], "maps/", 5))
	// {
	// 	free_exit(NULL, err_msg(ERR_USAGE, ERR));
	// }
	// read_map(*cub->map)
	// //check map content
	// if !(is_valid_map(*cub->map))
	// {
	// 	//free
	// }
	return (SUCCESS);
}

// static void	check_rgb(char *line, t_cub_data *cub)
// {
// 	if (!(strncomp(line[0], "NO", 2)) || \
// 		!(strncomp(line[0], "SO", 2)) || \
// 		!(strncomp(line[0], "WE", 2)) || \
// 		!(strncomp(line[0], "EA", 2)))
// 	else
// 		dprintf(ERror)
// }

// void	read_map(t_cub_data *cub)
// {
// 	int fd = open()
// 	while (1)
// 	{
// 		line = get_next_line(game->fd);
// 		if (!line)
// 			break ;
// 		if (count <= 5)
// 			check_dir(line, cub);
// 		else if (count > 5 && count <= 7)
// 			check_rgb(line, cub);


// 		else if (map_check(&line, &map_buf, game) == 1)
// 			error("Error\ninvalid input map\n");
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// }
