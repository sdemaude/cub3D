/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:00:40 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/25 10:05:57 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	err_msg(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (false);
}

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

bool	ft_strtoi(const char *nptr, int *value)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		*value = *value * 10 + (nptr[i] - '0');
		i++;
		if (*value + s > INT_MAX)
			return (false);
	}
	*value = *value * s;
	return (true);
}

char	**copy_map(char **map, t_point size)
{
	char	**copy_map;
	int		y;

	copy_map = malloc((size.y + 1) * sizeof(char *));
	if (!copy_map)
		return (NULL);
	y = 0;
	while (map[y])
	{
		copy_map[y] = ft_strdup(map[y]);
		if (!copy_map[y])
			break ;
		y++;
	}
	if (y < size.y)
	{
		free_tab(copy_map);
		return (NULL);
	}
	copy_map[y] = NULL;
	return (copy_map);
}

void	normalize_angle(double *angle)
{
	while (*angle < 0 || *angle >= 2 * M_PI)
	{
		if (*angle < 0)
			*angle += 2 * M_PI;
		else
			*angle -= 2 * M_PI;
	}
}

// void	display_map_file(char **map)
// {
// 	int	y;

// 	y = 0;
// 	while (map[y])
// 		printf("%s\n", map[y++]);
// }
