# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 23:44:09 by hypark            #+#    #+#              #
#    Updated: 2020/01/14 21:01:11 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pony
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

