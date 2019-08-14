# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 01:06:12 by hypark            #+#    #+#              #
#    Updated: 2019/08/14 06:02:33 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := printf
NAMELIB := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Wextra
SRC = $(filter-out main.c, $(wildcard *.c)) $(wildcard $(SRCDIR)/*.c)
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
	cp libft/libft.a ./$(NAMELIB)
	ar rc $(NAMELIB) $(OBJ)
	ranlib $(NAMELIB)
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c 
	$(CC) $(LIB) $(OBJ) -o $(NAME)

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
