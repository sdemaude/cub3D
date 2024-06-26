/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:01:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/10 17:16:12 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	find_extension(char *str, char *extension)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (extension[j] != '\0')
		j++;
	if (i < j)
		return (false);
	while (j >= 0)
	{
		if (str[i] != extension[j])
			return (false);
		i--;
		j--;
	}
	return (true);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	delete_tex(t_game *game, int exit_code)
{
	if (game->param.no.tex)
		mlx_delete_texture(game->param.no.tex);
	if (game->param.so.tex)
		mlx_delete_texture(game->param.so.tex);
	if (game->param.we.tex)
		mlx_delete_texture(game->param.we.tex);
	if (game->param.ea.tex)
		mlx_delete_texture(game->param.ea.tex);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2 || !find_extension(argv[1], ".cub"))
		return (err_msg(ERR_NOT_CUB), 1);
	if (!parse_file(argv[1], &game))
		return (delete_tex(&game, EXIT_FAILURE));
	display_map(&game);
	free_tab(game.map.map);
	return (delete_tex(&game, EXIT_SUCCESS));
}
