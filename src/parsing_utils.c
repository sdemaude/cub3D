/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:02:53 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/05 19:03:16 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	correct_char(char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E')
		return (false);
	return (true);
}

bool	player_pos(t_map *map, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (map->player.set)
			return (false);
		map->player.dir = c;
		map->player.pos.x = x;
		map->player.pos.y = y;
		map->player.set = true;
	}
	return (true);
}
