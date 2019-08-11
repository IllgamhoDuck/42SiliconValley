# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 23:36:24 by hypark            #+#    #+#              #
#    Updated: 2019/08/10 01:16:56 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c 
OBJ = $(SRC:.c=.o)
INCLUDES = libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

