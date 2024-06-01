/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:01:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/01 13:55:15 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	print_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}

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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !find_extension(argv[1], ".cub"))
		return (print_error("The program needs a .cub file as parameter\n"));
	if (!parse_file(argv[1], &game))
		return (print_error("Could not open the file\n")); //changes needed
	printf("C OK\n");
	return (0);
}
