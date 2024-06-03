/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:58:00 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/03 14:56:56 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	convert_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

bool	parse_value(char **line, int *value)
{
	*value = 0;
	if (!ft_strtoi(*line, value))
		return (err_msg(ERR_NOT_RGB));
	if (*value > 255 || *value < 0)
		return (err_msg(ERR_NOT_RGB));
	while (ft_isdigit(**line))
		(*line)++;
	return (true);
}

bool	skip_to_next(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
	if (**line != ',')
		return (err_msg(ERR_NO_COMMA));
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
		if (param->c.set)
			return (err_msg(ERR_MULT));
		param->c.rgb = convert_rgb(r, g, b);
		param->c.set = true;
	}
	else if (id == 'F')
	{
		if (param->f.set)
			return (err_msg(ERR_MULT));
		param->f.rgb = convert_rgb(r, g, b);
		param->f.set = true;
	}
	return (true);
}