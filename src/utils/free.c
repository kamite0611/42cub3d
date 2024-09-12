/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakashi <mnakashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:50:36 by akamite           #+#    #+#             */
/*   Updated: 2024/09/10 07:52:18 by mnakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

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
