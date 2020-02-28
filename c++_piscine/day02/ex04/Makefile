# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 01:54:36 by hypark            #+#    #+#              #
#    Updated: 2020/01/16 01:54:43 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := eval_expr
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

