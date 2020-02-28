# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 23:50:32 by hypark            #+#    #+#              #
#    Updated: 2020/01/15 02:35:22 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := logger
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

