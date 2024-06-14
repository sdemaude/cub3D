/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:38:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/14 14:22:27 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_start_angle(t_game *game)
{
	if (game->map.player.dir == 'N')
		game->map.player.theta = -M_PI_2;
	else if (game->map.player.dir == 'S')
		game->map.player.theta = M_PI_2;
	else if (game->map.player.dir == 'E')
		game->map.player.theta = 0;
	else if (game->map.player.dir == 'W')
		game->map.player.theta = M_PI;
}

void	key_control(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
	// raycasting(game);
}

void	start_game(t_game *game)
{
	set_start_angle(game);
	game->map.player.move_speed = 0.1;
	game->map.player.rotate_speed = M_PI * 0.05;
	mlx_loop_hook(game->mlx, key_control, game);
	mlx_loop(game->mlx);
}
