# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 23:36:24 by hypark            #+#    #+#              #
#    Updated: 2019/07/29 22:13:02 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c libft/*.c
OBJ = *.o
INCLUDES = get_next_line.h

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

