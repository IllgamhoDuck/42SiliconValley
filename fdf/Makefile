# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 22:46:07 by hypark            #+#    #+#              #
#    Updated: 2019/08/03 17:43:46 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf_test
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC = *.c $(wildcard $(SRCDIR)/*.c)
OBJ = *.o
INCLUDES = $(wildcard $(FTDIR)/*.h) $(MLXDIR)/mlx.h
LIB = $(FTDIR)/$(FTLIB) $(MLXDIR)/$(MLXLIB) \
	  -lmlx -framework OpenGL -framework Appkit

SRCDIR := ./src
INCDIR := ./includes

FT = libft
FTLIB = libft.a
FTDIR = ./libft

MLX = mlx
MLXLIB = mlxlib.a
MLXDIR = ./minilibx_macos

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(FT) $(MLX)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) -I $(INCLUDES) -L $(LIB) $(OBJ)

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
