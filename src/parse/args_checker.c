/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamite <akamite@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:31:51 by akamite           #+#    #+#             */
/*   Updated: 2024/07/29 23:56:59 by akamite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * コマンドライン引数が正しいかチェックする
 * - コマンドライン引数の数が正しいか
 * - ファイルパスが正しいか
 * - ファイルの内容が正しいか
 */
int args_checker(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
		free_exit(NULL, err_msg(ERR_USAGE,ERR));
	/** @TODO add argv checker */
	return SUCCESS;
}
