# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 23:44:09 by hypark            #+#    #+#              #
#    Updated: 2020/01/14 14:08:20 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook
CC := clang++
CFLAGS := -Wall -Wextra -Werror

SRC := ./*.cpp
INC := ./*.hpp
OBJ := ./*.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INC) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

