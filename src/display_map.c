/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:10:24 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/24 15:32:13 by ccormon          ###   ########.fr       */
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

void	display_floor_and_ceiling(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	game->ray.img = mlx_new_image(game->mlx, game->mlx->width,
		game->mlx->height);
	y = 0;
	while (y < game->ray.img->height / 2)
	{
		x = 0;
		while (x < game->ray.img->width)
			mlx_put_pixel(game->ray.img, x++, y, get_rgb(255, 244, 141));
		y++;
	}
	while (y < game->ray.img->height)
	{
		x = 0;
		while (x < game->ray.img->width)
			mlx_put_pixel(game->ray.img, x++, y, get_rgb(220, 232, 237));
		y++;
	}
	mlx_image_to_window(game->mlx, game->ray.img, 0, 0);
}

bool	display_map(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "tetraedre3D", true);
	if (!game->mlx)
		return (false);
	display_floor_and_ceiling(game);
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
