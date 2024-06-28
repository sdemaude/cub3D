/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:16:58 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 15:30:11 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_left(t_game *game)
{
	game->map.player.theta += game->map.player.rotate_speed;
	normalize_angle(&game->map.player.theta);
	raycasting(game);
}

void	rotate_right(t_game *game)
{
	game->map.player.theta -= game->map.player.rotate_speed;
	normalize_angle(&game->map.player.theta);
	raycasting(game);
}
