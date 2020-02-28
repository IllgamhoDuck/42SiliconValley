# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 23:50:32 by hypark            #+#    #+#              #
#    Updated: 2020/01/15 00:55:13 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := replace
CC := clang++
CFLAGS := -Wall -Wextra -Werror

SRC := ./*.cpp
OBJ := ./*.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

