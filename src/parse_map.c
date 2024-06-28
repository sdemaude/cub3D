/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:51:47 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/28 15:08:11 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	get_map(int fd, t_game *game)
{
	char	*map;
	char	*line;
	char	*tmp;

	map = get_next_line(fd);
	while (map && *map == '\n')
	{
		free(map);
		map = get_next_line(fd);
	}
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
	if (map && *map != '\n')
		game->map.map = ft_split(map, '\n');
	if (!game->map.map)
		return (close(fd), free(map), err_msg(ERR_NO_MAP));
	return (close(fd), free(map), free(line), true);
}

bool	get_map_data(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->size.x = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (!correct_char(map->map[i][j]))
				return (err_msg(ERR_INV_CHAR), false);
			if (!player_pos(map, map->map[i][j], j, i))
				return (err_msg(ERR_PLAYER), false);
			j++;
		}
		if (j > map->size.x)
			map->size.x = j;
		j = 0;
		i++;
	}
	map->size.y = i;
	if (!map->player.set)
		return (err_msg(ERR_PLAYER), false);
	return (true);
}

void	fill_space(t_map *map)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	while (map->map[++i])
	{
		while (map->map[i][j])
			j++;
		if (j < map->size.x)
		{
			tmp = map->map[i];
			map->map[i] = malloc(sizeof(char) * (map->size.x + 1));
			ft_strlcpy(map->map[i], tmp, map->size.x);
			free(tmp);
			while (j < map->size.x)
			{
				map->map[i][j] = ' ';
				j++;
			}
			map->map[i][j] = '\0';
		}
		j = 0;
	}
}

bool	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || tab[cur.y][cur.x] == ' '
		|| cur.x < 0 || cur.x >= size.x)
		return (false);
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F')
		return (true);
	tab[cur.y][cur.x] = 'F';
	if (!fill(tab, size, (t_point){cur.x - 1, cur.y})
		|| !fill(tab, size, (t_point){cur.x + 1, cur.y})
		|| !fill(tab, size, (t_point){cur.x, cur.y - 1})
		|| !fill(tab, size, (t_point){cur.x, cur.y + 1}))
		return (false);
	return (true);
}

bool	parse_map(int fd, t_game *game)
{
	char	**copy;

	if (!get_map(fd, game))
		return (false);
	if (!get_map_data(&game->map))
		return (false);
	fill_space(&game->map);
	copy = copy_map(game->map.map, game->map.size);
	if (!fill(copy, game->map.size, game->map.player.pos_init))
	{
		free_tab(copy);
		return (err_msg(ERR_NOT_CLOSE));
	}
	free_tab(copy);
	return (true);
}
