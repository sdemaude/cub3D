/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:39:37 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/14 17:32:07 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_on_map(t_map map, t_point_reel inter)
{
	int	x;
	int	y;

	if (inter.x < 0 || inter.y < 0 || (int)(inter.x / CB_SIZE) > map.size.x
		|| (int)(inter.y / CB_SIZE) > map.size.y)
		return (false);
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
			if (x++ == (int)(inter.x / CB_SIZE)
				&& y == (int)(inter.y / CB_SIZE))
				return (true);
		y++;
	}
	return (false);
}

bool	is_wall(t_map map, t_point_reel inter)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (x == (int)(inter.x / CB_SIZE) && y == (int)(inter.y / CB_SIZE))
			{
				if (map.map[y][x] == '1')
					return (true);
				else
					return (false);
			}
			x++;
		}
		y++;
	}
}

double	find_hor_inter(t_game *game)
{
	if (game->ray.theta < M_PI)
		game->ray.hor_inter.y = floor(game->map.player.pos.y / CB_SIZE)
			* CB_SIZE - OFFSET;
	else
		game->ray.hor_inter.y = ceil(game->map.player.pos.y / CB_SIZE)
			* CB_SIZE;
	game->ray.hor_inter.x = game->map.player.pos.x + (game->ray.hor_inter.y
		- game->map.player.pos.y) / tan(game->ray.theta);
	while (is_on_map(game->map, game->ray.hor_inter)
		&& !is_wall(game->map, game->ray.hor_inter))
	{

	}
}

void	raycasting(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = -game->mlx->width / 2;
	while (i < game->mlx->width)
	{
		game->ray.theta = game->map.player.theta + j * M_PI / 30;
		find_hor_inter(game);
		i++;
		j++;
	}
}
