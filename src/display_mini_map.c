/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:00:17 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/28 18:35:13 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

void	display_player(t_game *game, int cb_size)
{
	mlx_put_pixel(game->mini.img_player, 0, 0, get_rgb(240, 227, 107));
	mlx_put_pixel(game->mini.img_player, 0, 1, get_rgb(240, 227, 107));
	mlx_put_pixel(game->mini.img_player, 1, 0, get_rgb(240, 227, 107));
	mlx_put_pixel(game->mini.img_player, 1, 1, get_rgb(240, 227, 107));
	mlx_image_to_window(game->mlx, game->mini.img_player, game->map.player.pos.x
		/ cb_size, game->map.player.pos.y / cb_size);
}

void	display_mini_map_background(t_game *game)
{
	int	cb_size;
	int	x;
	int	y;

	cb_size = game->mini.cb_size;
	y = -1;
	while (++y < (int)game->mini.img_back->height)
	{
		x = -1;
		while (++x < (int)game->mini.img_back->width)
		{
			if (game->map.size.y <= y / cb_size
				|| game->map.size.x <= x / cb_size)
				continue ;
			if (game->map.map[y / cb_size][x / cb_size] == '1')
				mlx_put_pixel(game->mini.img_back, x, y, game->param.f.rgb);
			if (game->map.map[y / cb_size][x / cb_size] == '0'
				|| is_player(game->map.map[y / cb_size][x / cb_size]))
				mlx_put_pixel(game->mini.img_back, x, y, game->param.c.rgb);
		}
	}
	display_player(game, cb_size);
}
