/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:23:16 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/24 16:30:16 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wall(t_game *game, int x)
{
	double	wall_height;
	int		y;

	wall_height = CB_SIZE * ((game->mlx->height / 2) / tan(FOV_ANGLE / 2))
		/ (game->ray.len_inter);
	y = 0;
	while (y < game->mlx->height / 2 - wall_height / 2)
		mlx_put_pixel(game->ray.img, x, y++, get_rgb(255, 244, 141));
	while (y < game->mlx->height / 2 + wall_height / 2
		&& y < game->mlx->height)
		mlx_put_pixel(game->ray.img, x, y++, get_rgb(255, 255, 255));
	while (y < game->mlx->height)
		mlx_put_pixel(game->ray.img, x, y++, get_rgb(220, 232, 237));
}
