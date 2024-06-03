/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:53:58 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/03 11:37:35 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parse_file(char *filename, t_game *game)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (err_msg(ERR_OPEN));
	if (!parse_param(fd, game) || !parse_map(fd, game))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
