# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 16:07:18 by hypark            #+#    #+#              #
#    Updated: 2019/07/30 22:23:10 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c libft/ft_putstr.c libft/ft_putchar.c
OBJ = *.o
INCLUDES = fillet.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
