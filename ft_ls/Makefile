# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 21:12:21 by hypark            #+#    #+#              #
#    Updated: 2019/09/17 17:54:17 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ls
CC := gcc
CFLAGS := -Wall -Wextra -Wextra -O3
OBJ := *.o

SRCDIR := ./src
INCDIR := ./includes
FTDIR := ./libft
FTINC := includes

SRC = $(SRCDIR)/*.c
INCLUDES := -I$(FTDIR)/$(FTINC) -I$(INCDIR)
LIB := -L $(FTDIR) -lft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	$(MAKE) -sC $(FTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
	$(CC) $(LIB) $(OBJ) -o $@

clean:
	$(MAKE) -sC $(FTDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -sC $(FTDIR) fclean
	rm -f $(NAME)

re: fclean all
