void	set_mini_color(t_game *game, int color_f, int color_w, int color_p)
{
	uint32_t	x;
	uint32_t	y;

	y = -1;
	while (++y < game->map.mini.f->width)
	{
		x = 0;
		while (x < game->map.mini.f->height)
			mlx_put_pixel(game->map.mini.f, x++, y, color_f);
	}
	y = -1;
	while (++y < game->map.mini.w->width)
	{
		x = 0;
		while (x < game->map.mini.w->height)
			mlx_put_pixel(game->map.mini.w, x++, y, color_w);
	}
	y = -1;
	while (++y < game->map.mini.p->width)
	{
		x = 0;
		while (x < game->map.mini.p->height)
			mlx_put_pixel(game->map.mini.p, x++, y, color_p);
	}
}

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	set_img(t_game *game)
{
	game->map.mini.f = mlx_new_image(game->mlx, MINI_SQ_SIZE, MINI_SQ_SIZE);
	game->map.mini.w = mlx_new_image(game->mlx, MINI_SQ_SIZE, MINI_SQ_SIZE);
	game->map.mini.p = mlx_new_image(game->mlx, 2, 2);
	set_mini_color(game, get_rgb(200, 200, 200), get_rgb(100, 100, 100),
		get_rgb(255, 0, 0));
}

void	display_mini_map_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N'
				|| game->map.map[y][x] == 'S' || game->map.map[y][x] == 'E'
				|| game->map.map[y][x] == 'W')
				mlx_image_to_window(game->mlx, game->map.mini.f,
					x * MINI_SQ_SIZE, y * MINI_SQ_SIZE);
			if (game->map.map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->map.mini.w,
					x * MINI_SQ_SIZE, y * MINI_SQ_SIZE);
			x++;
		}
		y++;
	}
}

bool	display_mini_map(t_game *game)
{
	game->mlx = mlx_init(game->map.size.x * MINI_SQ_SIZE,
		game->map.size.y * MINI_SQ_SIZE, "tetraedre3d", true);
	if (!game->mlx)
		return (false);
	set_img(game);
	display_mini_map_background(game);
	mlx_image_to_window(game->mlx, game->map.mini.p, game->map.player.pos.x,
		game->map.player.pos.y);
	start_game(game);
	mlx_terminate(game->mlx);
	return (true);
}
