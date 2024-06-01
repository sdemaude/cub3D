/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:01:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/05/31 15:19:46 by sdemaude         ###   ########.fr       */
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

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

bool	parse_param(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
/*	if (ft_strncmp(line, "NO", 2))
	{
		clean_line(line);
		game->param.no_tex = ft_strdup(line);
	}
	else if (ft_strncmp(line, "SO", 2))
	{
		clean_line(line);
		game->param.so_tex = ft_strdup(line);
	}
	else if (ft_strncmp(line, "WE", 2))
	{
		clean_line(line);
		game->param.we_tex = ft_strdup(line);
	}
	else if (ft_strncmp(line, "EA", 2))
	{
		clean_line(line);
		game->param.ea_tex = ft_strdup(line);
	}*/
	printf("%s\n", line);
	return (true);
}

/*
bool	parse_map(int fd, t_params param)
{
	return (true);
}
*/
bool	parse_file(char *filename, t_game *game)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	parse_param(fd, game);
//	parse_map(fd, param);
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
