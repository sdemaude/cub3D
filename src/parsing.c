/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:53:58 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/01 18:25:00 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	convert_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

bool	parse_value(char **line, int *value)
{
	*value = 0;
	*value = ft_atoi(*line);
	if (*value > 255)
		return (false);
	while (ft_isdigit(**line))
		(*line)++;
	return (true);
}

bool	skip_to_next(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
	if (**line != ',')
		return (false);
	(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	return (true);
}

bool	parse_color(char id, char *line, t_param *param)
{
	int	r;
	int	g;
	int	b;

	if (!parse_value(&line, &r) || !skip_to_next(&line))
		return (false);
	if (!parse_value(&line, &g) || !skip_to_next(&line))
		return (false);
	if (!parse_value(&line, &b))
		return (false);
	if (id == 'C')
	{
		param->c->rgb = convert_rgb(r, g, b);
		param->c->set = true;
	}
	else if (id == 'F')
	{
		param->f->rgb = convert_rgb(r, g, b);
		param->f->set = true;
	}
	return (true);
}

bool	check_param(t_param *param)
{
	if (!param->f->set || !param->c->set || !param->no->set
		|| !param->so->set || !param->we->set || !param->ea->set)
		return (false);
	return (true);
}

bool	load_texture(t_dir *dir, char *path)
{
	dir->tex = mlx_load_png(path);
	if (!dir->tex)
		return (print_error("Texture not found !\n"), false);
	dir->set = true;
	return (true);
}

bool	parse_texture(char id, char *line, t_game *game)
{
	int	i;

	i = 0;
	while (!ft_isspace(line[i]))
		i++;
	if (line[i])
		line[i] = '\0';
	if (id == 'N')
		load_texture(game->param->no, line);
	else if (id == 'S')
		load_texture(game->param->so, line);
	else if (id == 'W')
		load_texture(game->param->we, line);
	else if (id == 'E')
		load_texture(game->param->ea, line);
	return (true);
}

bool	parse_param(int fd, t_game *game)
{
	char	*line;
	char	id;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		{
			id = *line;
			line++;
			while (ft_isspace(*line))
				line++;
			if (line)
				parse_color(id, line, game->param);
		}
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		{
			id = *line;
			line += 2;
			while (ft_isspace(*line))
				line++;
			if (line)
				parse_texture(id, line, game);
		}
		else if (*line != '\n')
			return (print_error("Incorrect line in file, must start by F, C, NO, SO, WE, or EA !\n"), false);
		line = get_next_line(fd);
		if (check_param(game->param))
			break ;
	}
	return (true);
}

/*bool	parse_map(int fd, t_params param)
{
	line = get_next_line(fd);
	while (line)
	{

	}
	return (true);
}*/

bool	parse_file(char *filename, t_game *game)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!parse_param(fd, game))// || !parse_map(fd, game))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
