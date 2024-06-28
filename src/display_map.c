/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:10:24 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 13:10:53 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_img(t_game *game)
{
	game->ray.img = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	mlx_image_to_window(game->mlx, game->ray.img, 0, 0);
	if (game->map.size.x >= game->map.size.y)
	{
		game->mini.cb_size = MINI_SIZE_MAX / game->map.size.x;
		game->mini.img_back = mlx_new_image(game->mlx, MINI_SIZE_MAX,
			game->map.size.y * game->mini.cb_size);
	}
	else
	{
		game->mini.cb_size = MINI_SIZE_MAX / game->map.size.x;
		game->mini.img_back = mlx_new_image(game->mlx, MINI_SIZE_MAX,
			game->map.size.y * game->mini.cb_size);
	}
	mlx_image_to_window(game->mlx, game->mini.img_back, 0, 0);
	game->mini.img_player = mlx_new_image(game->mlx, 2, 2);
	display_mini_map_background(game);
}

void	set_start_angle(t_game *game)
{
	if (game->map.player.dir == 'N')
		game->map.player.theta = M_PI_2;
	else if (game->map.player.dir == 'S')
		game->map.player.theta = 3 * M_PI_2;
	else if (game->map.player.dir == 'E')
		game->map.player.theta = 0;
	else if (game->map.player.dir == 'W')
		game->map.player.theta = M_PI;
}

bool	display_map(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "tetraedre3D", false);
	if (!game->mlx)
		return (false);
	set_img(game);
	set_start_angle(game);
	raycasting(game);
	start_game(game);
	mlx_terminate(game->mlx);
	return (true);
}
