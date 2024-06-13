/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:39:37 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/13 09:44:01 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_alpha(t_game *game)
{
	if (cos(game->ray.theta) == 0 || sin(game->ray.theta) == 0)
		game->ray.alpha = 0;
	else if (cos(game->ray.theta) > 0)
	{
		if (sin(game->ray.theta) > 0)
			game->ray.alpha = game->ray.theta;
		else if (sin(game->ray.theta) < 0)
			game->ray.alpha = 2 * M_PI - game->ray.theta;
	}
	else if (cos(game->ray.theta) < 0)
	{
		if (sin(game->ray.theta) > 0)
			game->ray.alpha = M_PI - game->ray.theta;
		else if (sin(game->ray.theta) < 0)
			game->ray.alpha = game->ray.theta - M_PI;
	}
}

bool	find_first_inter_hor(t_game *game)
{
	t_point_reel	a;
	t_point_reel	p;

	p.x = game->map.player.pos.x;
	p.y = game->map.player.pos.y;
	if (sin(game->ray.theta) == 0)
		return (false);
	else if (sin(game->ray.theta) < 0)
		a.y = floor(game->map.player.pos.y / CB_SIZE) * CB_SIZE;
	else
		a.y = floor(game->map.player.pos.y / CB_SIZE + 1) * CB_SIZE;
	game->ray.inter_len = fabs(p.y - a.y) * sin(game->ray.alpha);
	a.x = p.x - sqrt(pow(game->ray.inter_len, 2) - pow(p.y - a.y, 2));
	game->ray.inter_hor.x = a.x;
	game->ray.inter_hor.y = a.y;
	return (true);
}

bool	find_inter_hor(t_game *game)
{
	t_point	inter;

	if (!find_first_inter_hor(game))
		return (false);
	if (sin(game->ray.theta) < 0)
	{
		inter.y = game->ray.inter_hor.y / CB_SIZE - 1;
		inter.x = floor(game->ray.inter_hor.x + fabs(game->ray.inter_hor.y
			- inter.y) * tan(game->ray.alpha)) / CB_SIZE;
		while ()
	}
	else if (sin(game->ray.theta) > 0)
	{

	}
	return (true);
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
		set_alpha(game);
		find_inter_hor(game);
		i++;
		j++;
	}
}
