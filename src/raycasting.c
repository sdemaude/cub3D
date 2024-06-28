/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:39:37 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 15:28:17 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_on_map(t_map map, t_point_reel inter)
{
	int	x;
	int	y;

	if (inter.x < 0 || inter.y < 0 || inter.x >= map.size.x * CB_SIZE
		|| inter.y >= map.size.y * CB_SIZE || isnan(inter.x)
		|| isnan(inter.y))
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
	return (false);
}

void	inter_hor(t_game *game, double hor_inter_len)
{
	if (game->ray.theta < M_PI)
		game->ray.face = 'S';
	else
		game->ray.face = 'N';
	game->ray.inter = game->ray.hor_inter;
	game->ray.len_inter = hor_inter_len
		* cos(fabs(game->map.player.theta - game->ray.theta));
}

void	inter_ver(t_game *game, double ver_inter_len)
{
	if (game->ray.theta >= M_PI_2 && game->ray.theta < 3 * M_PI_2)
		game->ray.face = 'E';
	else
		game->ray.face = 'W';
	game->ray.inter = game->ray.ver_inter;
	game->ray.len_inter = ver_inter_len
		* cos(fabs(game->map.player.theta - game->ray.theta));
}

void	raycasting(t_game *game)
{
	double	hor_inter_len;
	double	ver_inter_len;
	int		i;

	game->ray.theta = game->map.player.theta - FOV_ANGLE / 2;
	i = game->mlx->width - 1;
	while (i >= 0)
	{
		normalize_angle(&game->ray.theta);
		hor_inter_len = find_hor_inter(game);
		ver_inter_len = find_ver_inter(game);
		if (hor_inter_len <= ver_inter_len)
			inter_hor(game, hor_inter_len);
		else
			inter_ver(game, ver_inter_len);
		draw_wall(game, i--);
		game->ray.theta += FOV_ANGLE / game->mlx->width;
	}
}
