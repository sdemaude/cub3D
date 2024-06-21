/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:16:58 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/21 18:21:31 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_left(t_game *game)
{
	game->map.player.theta -= game->map.player.rotate_speed;
	while (game->map.player.theta <= 0)
		game->map.player.theta += 2 * M_PI;
	while (game->map.player.theta > 2 * M_PI)
		game->map.player.theta -= 2 * M_PI;
}

void	rotate_right(t_game *game)
{
	game->map.player.theta += game->map.player.rotate_speed;
	while (game->map.player.theta <= 0)
		game->map.player.theta += 2 * M_PI;
	while (game->map.player.theta > 2 * M_PI)
		game->map.player.theta -= 2 * M_PI;
}
