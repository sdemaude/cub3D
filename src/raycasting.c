/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:39:37 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/21 19:19:27 by ccormon          ###   ########.fr       */
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
	t_point_reel	hor_inter;

	if (game->ray.theta < M_PI)
		hor_inter.y = floor(game->map.player.pos.y / CB_SIZE)
			* CB_SIZE - OFFSET;
	else
		hor_inter.y = ceil(game->map.player.pos.y / CB_SIZE) * CB_SIZE;
	hor_inter.x = game->map.player.pos.x + (hor_inter.y
		- game->map.player.pos.y) / tan(game->ray.theta);
	while (is_on_map(game->map, hor_inter) && !is_wall(game->map, hor_inter))
	{
		if (game->ray.theta < M_PI)
		{
			hor_inter.x += CB_SIZE / tan(game->ray.theta);
			hor_inter.y -= CB_SIZE;
		}
		else
		{
			hor_inter.x -= CB_SIZE / tan(game->ray.theta);
			hor_inter.y += CB_SIZE;
		}
	}
	if (!is_on_map(game->map, hor_inter))
		return (INFINITY);
	else
		return (sqrt(pow(game->map.player.pos.x - hor_inter.x, 2)
			+ pow(game->map.player.pos.y - hor_inter.y, 2)));
}

double	find_ver_inter(t_game *game)
{
	t_point_reel	ver_inter;

	if (game->ray.theta >= M_PI_2 && game->ray.theta < 3 * M_PI_2)
		ver_inter.x = floor(game->map.player.pos.x / CB_SIZE)
			* CB_SIZE - OFFSET;
	else
		ver_inter.x = ceil(game->map.player.pos.x / CB_SIZE)
			* CB_SIZE;
	ver_inter.y = game->map.player.y + (ver_inter.x
		- game->map.player.pos.x) * tan(game->ray.theta);
	while (is_on_map(game->map, ver_inter) && !is_wall(game->map, ver_inter))
	{
		if (game->ray.theta >= M_PI_2 && game->ray.theta < 3 * M_PI_2)
		{
			ver_inter.x -= CB_SIZE;
			ver_inter.y -= CB_SIZE * tan(game->ray.theta);
		}
		else
		{
			ver_inter.x += CB_SIZE;
			ver_inter.y += CB_SIZE * tan(game->ray.theta);
		}
	}
	if (!is_on_map(game->map, ver_inter))
		return (INFINITY);
	else
		return (sqrt(pow(game->map.player.pos.x - ver_inter.x, 2)
			+ pow(game->map.player.pos.y - ver_inter.y, 2)));
}

void	raycasting(t_game *game)
{
	double	hor_inter_len;
	double	ver_inter_len;
	int		i;
	int		j;

	i = 0;
	j = -game->mlx->width / 2;
	while (i < game->mlx->width)
	{
		game->ray.theta = game->map.player.theta + j * M_PI / 30;
		hor_inter_len = find_hor_inter(game);
		ver_inter_len = find_ver_inter(game);
		i++;
		j++;
	}
}
