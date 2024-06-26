/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:10:24 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/26 19:42:29 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	game->ray.img = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	mlx_image_to_window(game->mlx, game->ray.img, 0, 0);
	set_start_angle(game);
	raycasting(game);
	start_game(game);
	mlx_terminate(game->mlx);
	return (true);
}

// mini_map
// bool	display_map(t_game *game)
// {
// 	game->mlx = mlx_init(game->map.size.x * MINI_SQ_SIZE,
// 			game->map.size.y * MINI_SQ_SIZE, "tetraedre3D", true);
// 	if (!game->mlx)
// 		return (false);
// 	set_img(game);
// 	display_mini_map_background(game);
// 	mlx_image_to_window(game->mlx, game->map.mini.p,
// 		game->map.player.pos.x * MINI_SQ_SIZE,
// 		game->map.player.pos.y * MINI_SQ_SIZE);
// 	start_game(game);
// 	mlx_terminate(game->mlx);
// 	return (true);
// }
