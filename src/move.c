/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:49:00 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/10 17:16:05 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// printf("theta = %lf\tx = %lf\ty = %lf\tcos(theta) = %lf\tsin(theta) = %lf\t
// new_x = %lf\tnew_y = %lf\n", theta, game->map.player.pos.x,
// game->map.player.pos.y, cos(theta), sin(theta),
// game->map.player.pos.x + cos(theta) * game->map.player.move_speed,
// game->map.player.pos.y + sin(theta) * game->map.player.move_speed);

void	move_up(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta) * speed;
	y = game->map.player.pos.y + sin(theta) * speed;
	if (game->map.map[y][x] == '1')
		return ;
	game->map.player.pos.x += cos(theta) * speed;
	game->map.player.pos.y += sin(theta) * speed;
	game->map.mini.p->instances[0].x = game->map.player.pos.x * MINI_SQ_SIZE;
	game->map.mini.p->instances[0].y = game->map.player.pos.y * MINI_SQ_SIZE;
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
	y = game->map.player.pos.y + sin(theta + M_PI) * speed;
	if (game->map.map[y][x] == '1')
		return ;
	game->map.player.pos.x += cos(theta + M_PI) * speed;
	game->map.player.pos.y += sin(theta + M_PI) * speed;
	game->map.mini.p->instances[0].x = game->map.player.pos.x * MINI_SQ_SIZE;
	game->map.mini.p->instances[0].y = game->map.player.pos.y * MINI_SQ_SIZE;
}

void	move_left(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta + M_PI * 1.5) * speed;
	y = game->map.player.pos.y + sin(theta + M_PI * 1.5) * speed;
	if (game->map.map[y][x] == '1')
		return ;
	game->map.player.pos.x += cos(theta + M_PI * 1.5) * speed;
	game->map.player.pos.y += sin(theta + M_PI * 1.5) * speed;
	game->map.mini.p->instances[0].x = game->map.player.pos.x * MINI_SQ_SIZE;
	game->map.mini.p->instances[0].y = game->map.player.pos.y * MINI_SQ_SIZE;
}

void	move_right(t_game *game)
{
	double	theta;
	double	speed;
	int		x;
	int		y;

	theta = game->map.player.theta;
	speed = game->map.player.move_speed;
	x = game->map.player.pos.x + cos(theta + M_PI * 1.5) * speed;
	y = game->map.player.pos.y + sin(theta + M_PI * 1.5) * speed;
	if (game->map.map[y][x] == '1')
		return ;
	game->map.player.pos.x += cos(theta + M_PI * 0.5) * speed;
	game->map.player.pos.y += sin(theta + M_PI * 0.5) * speed;
	game->map.mini.p->instances[0].x = game->map.player.pos.x * MINI_SQ_SIZE;
	game->map.mini.p->instances[0].y = game->map.player.pos.y * MINI_SQ_SIZE;
}
