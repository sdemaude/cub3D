/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:59:27 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/04 13:56:13 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	load_texture(t_dir *dir, char *path)
{
	if (dir->set)
		return (err_msg(ERR_MULT));
	dir->tex = mlx_load_png(path);
	if (!dir->tex)
		return (err_msg(ERR_TEX));
	dir->set = true;
	return (true);
}

char	*get_name(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n')
		i++;
	while (ft_isspace(line[i]))
	{
		line[i] = '\0';
		i--;
	}
	line[i] = '\0';
	return (line);
}

bool	parse_texture(char id, char *line, t_param *param)
{
	char	*name;

	name = get_name(line);
	if (id == 'N' && !load_texture(&param->no, name))
		return (false);
	else if (id == 'S' && !load_texture(&param->so, name))
		return (false);
	else if (id == 'W' && !load_texture(&param->we, name))
		return (false);
	else if (id == 'E' && !load_texture(&param->ea, name))
		return (false);
	return (true);
}
