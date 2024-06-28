/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:00:17 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 13:13:54 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	display_mini_map_background(t_game *game)
{
	int			cb_size;
	uint32_t	x;
	uint32_t	y;

	cb_size = game->mini.cb_size;
	y = 0;
	while (y < game->mini.img_back->height)
	{
		x = 0;
		while (x < game->mini.img_back->width)
		{
			if (game->map.map[y / cb_size][x / cb_size] == '1')
				mlx_put_pixel(game->mini.img_back, x, y, game->param.f.rgb);
			if (game->map.map[y / cb_size][x / cb_size] == '0'
				|| game->map.map[y / cb_size][x / cb_size] == 'N'
				|| game->map.map[y / cb_size][x / cb_size] == 'S'
				|| game->map.map[y / cb_size][x / cb_size] == 'E'
				|| game->map.map[y / cb_size][x / cb_size] == 'W')
				mlx_put_pixel(game->mini.img_back, x, y, game->param.c.rgb);
			x++;
		}
		y++;
	}
	mlx_put_pixel(game->mini.img_player, 0, 0, get_rgb(240, 227, 107));
	mlx_put_pixel(game->mini.img_player, 0, 1, get_rgb(240, 227, 107));
	mlx_put_pixel(game->mini.img_player, 1, 0, get_rgb(240, 227, 107));
	mlx_put_pixel(game->mini.img_player, 1, 1, get_rgb(240, 227, 107));
	mlx_image_to_window(game->mlx, game->mini.img_player, game->map.player.pos.x
		/ cb_size, game->map.player.pos.y / cb_size);
}
