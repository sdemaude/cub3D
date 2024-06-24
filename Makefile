# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 17:41:22 by sdemaude          #+#    #+#              #
#    Updated: 2024/06/24 15:21:52 by ccormon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		= -Wall -Wextra -Werror -g
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= lib/minilibx
LIBMLX 		= $(MLX)/libmlx42.a

LIBFTDIR	= lib/libft
LIBFT		= $(LIBFTDIR)/libft.a

SRCDIR		= src
SRCFILE		= main\
			  utils\
			  parsing\
			  parse_param\
			  color\
			  texture\
			  parse_map\
			  parsing_utils\
			  display_map\
			  display_mini_map\
			  start_game\
			  move\
			  rotate\
			  raycasting\
			  draw_wall

SRC 		= $(addprefix $(SRCDIR)/,$(addsuffix .c,$(SRCFILE)))

OBJDIR		= obj
OBJ 		= $(addprefix $(OBJDIR)/,$(addsuffix .o,$(SRCFILE)))

all: $(OBJDIR) $(NAME)

$(LIBFT): $(LIBFTDIR)
		make -C $(LIBFTDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLX)
	$(RM) -r $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX)

re: fclean all

c: all clean

.PHONY:		all bonus clear clean fclean re c
