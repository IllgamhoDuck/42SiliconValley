# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 21:42:42 by hypark            #+#    #+#              #
#    Updated: 2019/08/16 21:54:01 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := printf
CC := gcc
CFLAGS := -Wall -Wextra -Wextra
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ := *.o

SRCDIR := ./src
INCDIR := ../includes

INCLUDES := -I$(INCDIR)

all: $(NAME)
.PHONY: all clean fclean re

$(NAME):
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all
