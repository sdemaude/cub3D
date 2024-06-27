/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:23:16 by ccormon           #+#    #+#             */
/*   Updated: 2024/06/27 09:34:24 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_texture_t	*get_tex(t_game *game)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (game->ray.face == 'N')
		texture = game->param.no.tex;
	else if (game->ray.face == 'S')
		texture = game->param.so.tex;
	else if (game->ray.face == 'E')
		texture = game->param.ea.tex;
	else if (game->ray.face == 'W')
		texture = game->param.we.tex;
	return (texture);
}

int	get_pxl_img(mlx_texture_t *texture, t_point_reel t)
{
	uint8_t	*pixel;

	t.y *= texture->height - 1;
	t.x *= texture->width - 1;
	pixel = texture->pixels + ((int)t.y * texture->width
			+ (texture->width - 1 - (int)t.x)) * texture->bytes_per_pixel;
	return (get_rgb(pixel[0], pixel[1], pixel[2]));
}

int	draw_texture(t_game *game, double wall_height, int x, int y)
{
	mlx_texture_t	*texture;
	double			step;
	t_point_reel	t;

	texture = get_tex(game);
	step = 1 / wall_height;
	if (game->ray.face == 'N' || game->ray.face == 'S')
		t.x = fmod(game->ray.inter.x, CB_SIZE) / CB_SIZE;
	else if (game->ray.face == 'E' || game->ray.face == 'W')
		t.x = fmod(game->ray.inter.y, CB_SIZE) / CB_SIZE;
	if (game->ray.face == 'S' || game->ray.face == 'W')
		t.x = 1 - t.x;
	t.y = (double)(y - (game->mlx->height - wall_height) / 2)
		/ (double)wall_height;
	while (y < (game->mlx->height + wall_height) / 2
		&& y < game->mlx->height)
	{
		mlx_put_pixel(game->ray.img, x, y++, get_pxl_img(texture, t));
		t.y += step;
	}
	return (y);
}

void	draw_wall(t_game *game, int x)
{
	double	wall_height;
	int		y;

	wall_height = CB_SIZE * ((game->mlx->height / 2) / tan(FOV_ANGLE / 2))
		/ (game->ray.len_inter);
	y = 0;
	while (y < (game->mlx->height - wall_height) / 2)
		mlx_put_pixel(game->ray.img, x, y++, game->param.c.rgb);
	y = draw_texture(game, wall_height, x, y);
	while (y < game->mlx->height)
		mlx_put_pixel(game->ray.img, x, y++, game->param.f.rgb);
}
