# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 22:46:07 by hypark            #+#    #+#              #
#    Updated: 2019/08/09 02:48:29 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = *.o
INCLUDES = -I$(FTDIR) -I$(MLXDIR) -I$(INCDIR) 
LIB = -L $(FTDIR) -L $(MLXDIR) -lft \
	  -lmlx -framework OpenGL -framework Appkit

SRCDIR := ./src
INCDIR := ./includes

FT = libft
FTLIB = libft.a
FTDIR = ./libft

MLX = mlx
MLXLIB = libmlx.a
MLXDIR = ./minilibx_macos

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(FT) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
	$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME) 

.PHONY: libft
$(FT):
	$(MAKE) -sC $(FTDIR)

$(MLX):
	$(MAKE) -sC $(MLXDIR)

clean:
	$(MAKE) -sC $(FTDIR) clean
	$(MAKE) -sC $(MLXDIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(FTDIR) fclean

re: fclean all
