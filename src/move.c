/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:49:00 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/08 15:23:21 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	move_up(t_game *game)
// {
// 	double	theta;
// 	int		x;
// 	int		y;

// 	theta = game->map.player.angle;
// 	printf("theta = %lf\tx = %d\ty = %d\n", theta, game->map.player.pos.x,
// 		game->map.player.pos.y);
// 	x = (game->map.player.pos.x + cos(theta)) / CB_SIZE;
// 	y = (game->map.player.pos.y + sin(theta)) / CB_SIZE;
// 	if (game->map.map[y][x] == '1')
// 		return ;
// 	game->map.player.pos.x += cos(theta);
// 	game->map.player.pos.y += sin(theta);
// 	game->map.mini.p->instances[0].x += cos(theta);
// 	game->map.mini.p->instances[0].y += sin(theta);
// 	printf("cos(theta) = %lf\tsin(theta) = %lf\tnew_x = %d\tnew_y = %d\n",
// 		cos(theta), sin(theta), game->map.player.pos.x, game->map.player.pos.y);
// }
