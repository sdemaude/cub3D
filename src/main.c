/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:01:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/05 15:06:55 by sdemaude         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2 || !find_extension(argv[1], ".cub"))
		return (err_msg(ERR_NOT_CUB), 1);
	if (!parse_file(argv[1], &game))
		return (EXIT_FAILURE);
	printf("C OK\n");
	free_tab(game.map.map);
	mlx_delete_texture(game.param.no.tex);
	mlx_delete_texture(game.param.so.tex);
	mlx_delete_texture(game.param.we.tex);
	mlx_delete_texture(game.param.ea.tex);
	return (EXIT_SUCCESS);
}
