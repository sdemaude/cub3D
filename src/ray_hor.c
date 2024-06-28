/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:47:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/28 14:02:45 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hor_inter(t_game *game)
{
	if (game->ray.theta < M_PI)
	{
		game->ray.hor_inter.x += CB_SIZE / tan(game->ray.theta);
		game->ray.hor_inter.y -= CB_SIZE;
	}
	else
	{
		game->ray.hor_inter.x -= CB_SIZE / tan(game->ray.theta);
		game->ray.hor_inter.y += CB_SIZE;
	}
}

double	find_hor_inter(t_game *game)
{
	if (game->ray.theta < M_PI)
		game->ray.hor_inter.y = floor(game->map.player.pos.y / CB_SIZE)
			* CB_SIZE - OFFSET;
	else
		game->ray.hor_inter.y = floor(game->map.player.pos.y / CB_SIZE)
			* CB_SIZE + CB_SIZE;
	game->ray.hor_inter.x = game->map.player.pos.x - (game->ray.hor_inter.y
			- game->map.player.pos.y) / tan(game->ray.theta);
	while (is_on_map(game->map, game->ray.hor_inter)
		&& !is_wall(game->map, game->ray.hor_inter))
		hor_inter(game);
	if (!is_on_map(game->map, game->ray.hor_inter))
		return (INFINITY);
	else
		return (sqrt(pow(game->map.player.pos.x - game->ray.hor_inter.x, 2)
				+ pow(game->map.player.pos.y - game->ray.hor_inter.y, 2)));
}
