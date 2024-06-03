/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:45:59 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/03 15:52:54 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_param(t_param *param)
{
	if (!param->f.set || !param->c.set || !param->no.set
		|| !param->so.set || !param->we.set || !param->ea.set)
		return (false);
	return (true);
}

bool	parse_which(char c, t_game *game, char *line)
{
	char	id;

	id = *line;
	if (c == 'T')
		line++;
	line++;
	while (ft_isspace(*line))
		line++;
	if (line && c == 'C' && !parse_color(id, line, &game->param))
		return (false);
	else if (line && c == 'T' && !parse_texture(id, line, &game->param))
		return (false);
	return (true);
}

bool	is_texture(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (true);
	return (false);
}

bool	is_color(char *line)
{
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (true);
	return (false);
}

bool	parse_param(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (is_color(line))
		{
			if (!parse_which('C', game, line))
				return (free(line), false);
		}
		else if (is_texture(line))
		{
			if (!parse_which('T', game, line))
				return (free(line), false);
		}
		else if (*line != '\n')
			return (err_msg(ERR_LINE));
		free(line);
		line = get_next_line(fd);
		if (check_param(&game->param))
			break ;
	}
	free(line);
	if (!check_param(&game->param))
		return (err_msg(ERR_MISS));
	return (true);
}
