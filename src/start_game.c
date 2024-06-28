/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:38:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 13:16:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mouse_control(t_game *game)
{
	t_point	mouse_pos;

	mlx_get_mouse_pos(game->mlx, &mouse_pos.x, &mouse_pos.y);
	game->map.player.theta += 0.004
		* (mouse_pos.x - game->old_mouse_pos);
	normalize_angle(&game->map.player.theta);
	raycasting(game);
	game->old_mouse_pos = mouse_pos.x;
}

void	key_control(void *param)
{
	t_game	*game;

	game = param;
	mouse_control(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
	game->mini.img_player->instances[0].x = game->mini.cb_size
		* game->map.player.pos.x / CB_SIZE;
	game->mini.img_player->instances[0].y = game->mini.cb_size
		* game->map.player.pos.y / CB_SIZE;
}

void	start_game(t_game *game)
{
	t_point	mouse_pos;

	mlx_get_mouse_pos(game->mlx, &mouse_pos.x, &mouse_pos.y);
	game->old_mouse_pos = mouse_pos.x;
	game->map.player.move_speed = 2;
	game->map.player.rotate_speed = 0.06;
	mlx_loop_hook(game->mlx, key_control, game);
	mlx_loop(game->mlx);
}
