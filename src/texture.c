/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:59:27 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/03 15:38:10 by sdemaude         ###   ########.fr       */
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

bool	parse_texture(char id, char *line, t_param *param)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isspace(line[i]) && line[i] != '\n')
		i++;
	if (line[i])
		line[i] = '\0';
	if (id == 'N' && !load_texture(&param->no, line))
		return (false);
	else if (id == 'S' && !load_texture(&param->so, line))
		return (false);
	else if (id == 'W' && !load_texture(&param->we, line))
		return (false);
	else if (id == 'E' && !load_texture(&param->ea, line))
		return (false);
	return (true);
}
