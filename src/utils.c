/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:00:40 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/24 14:25:47 by ccormon          ###   ########.fr       */
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

void	display_map_file(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		printf("%s\n", map[y++]);
}

