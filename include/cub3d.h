/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:05:23 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/01 17:21:31 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/gnl/get_next_line.h"
# include "../lib/minilibx/mlx42.h"

typedef struct s_dir
{
	mlx_texture_t	*tex;
	bool			set;

}	t_dir;

typedef struct s_alt
{
	int		rgb;
	bool	set;
}	t_alt;

typedef struct s_param
{
	t_dir	*no;
	t_dir	*so;
	t_dir	*we;
	t_dir	*ea;
	t_alt	*f;
	t_alt	*c;
	char	**map;
	int		map_width;
	int		map_height;
}	t_param;

typedef struct s_game
{
	mlx_t		*mlx;
	t_param		*param;
}	t_game;

bool	parse_file(char *filename, t_game *game);
int		print_error(char *str);

#endif
