# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 01:06:12 by hypark            #+#    #+#              #
#    Updated: 2019/08/16 12:51:41 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := printf
NAMELIB := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Wextra
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ := *.o

SRCDIR := ./src
INCDIR := ./includes

FT := libft
FTLIB := libft.a
FTDIR := ./libft

INCLUDES := -I$(FTDIR) -I$(INCDIR)
LIB := -L $(FTDIR) -L ./ -lftprintf -lft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(FT)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
	ar rc $(NAMELIB) $(OBJ)
	ranlib $(NAMELIB)

test:
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c 
	$(CC) $(LIB) main.o -o $(NAME)

.PHONY: libft
$(FT):
	$(MAKE) -sC $(FTDIR)

clean:
	$(MAKE) -sC $(FTDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -sC $(FTDIR) fclean
	rm -f $(NAMELIB)
	rm -f $(NAME)

re: fclean all
