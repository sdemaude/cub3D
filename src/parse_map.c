/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:08:09 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/03 17:38:59 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parse_map(int fd, t_game *game)
{
	char	*map;
	char	*line;
	char	*tmp;

	map = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(map, line);
		free(line);
		free(map);
		map = tmp;
	}
	if (map)
		game->param.map = ft_split(map, '\n');
	free(map);
	close(fd);
	if (!game->param.map)
		return (false);//(err_msg(MAP));
	free(line);
	return (true);
}
