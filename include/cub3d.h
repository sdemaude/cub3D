/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:05:23 by sdemaude          #+#    #+#             */
/*   Updated: 2024/06/06 14:55:54 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/gnl/get_next_line.h"
# include "../lib/minilibx/mlx42.h"

//**ERROR**MESSSAGES**
# define ERR_NOT_CUB "The program needs a .cub file as parameter\n"
# define ERR_OPEN "Could not open, check permissions or if is a directory\n"
# define ERR_NO_COMMA "The RGB values need to be separated by commas\n" 
# define ERR_NOT_RGB "Invalid RGB value (min : 0, max : 255)\n"
# define ERR_LINE "Incorrect line, must start by F, C, NO, SO, WE, or EA \
(map should be last in file)\n"
# define ERR_MISS "Missing parameters for the map creation\n"
# define ERR_TEX "Texture could not be loaded\n"
# define ERR_MULT "Parameter has already been initialized\n"
# define ERR_NO_MAP "No map in file\n"
# define ERR_INV_CHAR "Invalid character in map (not 1, 0, N, S, W, E or \
space)\n"
# define ERR_PLAYER "Multiple player position\n"
# define ERR_NOT_CLOSE "The map is not closed\n"

//**STRUCT**
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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	bool	set;
	t_point	pos;
	char	dir; // N, S, W, E
}	t_player;

typedef struct s_map
{
	char		**map;
	t_point		size;
	t_player	player;
}	t_map;

typedef struct s_param
{
	t_dir	no;
	t_dir	so;
	t_dir	we;
	t_dir	ea;
	t_alt	f;
	t_alt	c;
}	t_param;

typedef struct s_game
{
	mlx_t		*mlx;
	t_param		param;
	t_map		map;
}	t_game;

//**FONCTIONS**

//UTILS
bool	ft_isspace(char c);
bool	err_msg(char *str);
bool	ft_strtoi(const char *nptr, int *value);

//PARSING
bool	parse_file(char *filename, t_game *game);

//PARSING_UTILS
bool	correct_char(char c);
bool	player_pos(t_map *map, char c, int x, int y);

//PARSE_PARAM
bool	parse_param(int fd, t_game *game);

//COLORS
bool	parse_color(char id, char *line, t_param *param);

//TEXTURE
bool	parse_texture(char id, char *line, t_param *param);

//PARSE_MAP
bool	parse_map(int fd, t_game *game);

#endif
