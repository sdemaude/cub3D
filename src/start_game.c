/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:38:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/08 16:03:42 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_start_angle(t_game *game)
{
	if (game->map.player.dir == 'N')
		game->map.player.angle = PI;
	else if (game->map.player.dir == 'S')
		game->map.player.angle = 0;
	else if (game->map.player.dir == 'E')
		game->map.player.angle = -PI / 2;
	else if (game->map.player.dir == 'W')
		game->map.player.angle = PI / 2;
}

void	key_control(void *param)
{
	t_game *game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	// 	move_up(game);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	// 	move_down(game);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_E))
	// 	move_right(game);
	// else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	// 	move_left(game);
}

void	start_game(t_game *game)
{
	// set_start_angle(game);
	printf("is it here ? 1\n");
	mlx_loop_hook(game->mlx, key_control, game);
	printf("is it here ? 2\n");
	mlx_loop(game->mlx);
	printf("is it here ? 3\n");
}
