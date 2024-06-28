/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:48:15 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/28 14:02:31 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ver_inter(t_game *game)
{
	if (game->ray.theta >= M_PI_2 && game->ray.theta < 3 * M_PI_2)
	{
		game->ray.ver_inter.x -= CB_SIZE;
		game->ray.ver_inter.y += CB_SIZE * tan(game->ray.theta);
	}
	else
	{
		game->ray.ver_inter.x += CB_SIZE;
		game->ray.ver_inter.y -= CB_SIZE * tan(game->ray.theta);
	}
}

double	find_ver_inter(t_game *game)
{
	if (game->ray.theta >= M_PI_2 && game->ray.theta < 3 * M_PI_2)
		game->ray.ver_inter.x = floor(game->map.player.pos.x / CB_SIZE)
			* CB_SIZE - OFFSET;
	else
		game->ray.ver_inter.x = floor(game->map.player.pos.x / CB_SIZE)
			* CB_SIZE + CB_SIZE;
	game->ray.ver_inter.y = game->map.player.pos.y - (game->ray.ver_inter.x
			- game->map.player.pos.x) * tan(game->ray.theta);
	while (is_on_map(game->map, game->ray.ver_inter)
		&& !is_wall(game->map, game->ray.ver_inter))
		ver_inter(game);
	if (!is_on_map(game->map, game->ray.ver_inter))
		return (INFINITY);
	else
		return (sqrt(pow(game->map.player.pos.x - game->ray.ver_inter.x, 2)
				+ pow(game->map.player.pos.y - game->ray.ver_inter.y, 2)));
}
