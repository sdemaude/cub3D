/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:10:24 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/12 14:55:47 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	display_floor_and_ceiling(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	game->param.f.img = mlx_new_image(game->mlx, game->mlx->width,
		game->mlx->height);
	y = 0;
	while (y < game->param.f.img->height)
	{
		x = 0;
		while (x < game->param.f.img->width)
			mlx_put_pixel(game->param.f.img, x++, y, get_rgb(220, 100, 3));
		y++;
	}
	game->param.c.img = mlx_new_image(game->mlx, game->mlx->width,
		game->mlx->height / 2);
	y = 0;
	while (y < game->param.c.img->height)
	{
		x = 0;
		while (x < game->param.c.img->width)
			mlx_put_pixel(game->param.c.img, x++, y, get_rgb(225, 30, 0));
		y++;
	}
	mlx_image_to_window(game->mlx, game->param.f.img, 0, 0);
	mlx_image_to_window(game->mlx, game->param.c.img, 0, game->mlx->height / 2);
}

bool	display_map(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "tetraedre3D", true);
	if (!game->mlx)
		return (false);
	display_floor_and_ceiling(game);
	// raycasting(game);
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
