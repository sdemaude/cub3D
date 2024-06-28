/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:49:00 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 13:37:33 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_up(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta) * speed;
	y = game->map.player.pos.y - sin(theta) * speed;
	if (game->map.map[y / CB_SIZE][x / CB_SIZE] == '1')
		return ;
	game->map.player.pos.x += cos(theta) * speed;
	game->map.player.pos.y -= sin(theta) * speed;
	raycasting(game);
}

void	move_down(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta + M_PI) * speed;
	y = game->map.player.pos.y - sin(theta + M_PI) * speed;
	if (game->map.map[y / CB_SIZE][x / CB_SIZE] == '1')
		return ;
	game->map.player.pos.x += cos(theta + M_PI) * speed;
	game->map.player.pos.y -= sin(theta + M_PI) * speed;
	raycasting(game);
}

void	move_left(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta + 3 * M_PI_2) * speed;
	y = game->map.player.pos.y - sin(theta + 3 * M_PI_2) * speed;
	if (game->map.map[y / CB_SIZE][x / CB_SIZE] == '1')
		return ;
	game->map.player.pos.x += cos(theta + 3 * M_PI_2) * speed;
	game->map.player.pos.y -= sin(theta + 3 * M_PI_2) * speed;
	raycasting(game);
}

void	move_right(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta + M_PI_2) * speed;
	y = game->map.player.pos.y - sin(theta + M_PI_2) * speed;
	if (game->map.map[y / CB_SIZE][x / CB_SIZE] == '1')
		return ;
	game->map.player.pos.x += cos(theta + M_PI_2) * speed;
	game->map.player.pos.y -= sin(theta + M_PI_2) * speed;
	raycasting(game);
}
