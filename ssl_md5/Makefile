# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 13:32:30 by hypark            #+#    #+#              #
#    Updated: 2019/08/23 21:40:52 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ssl
CC := gcc
CFLAGS := -Wall -Wextra -Wextra -g
OBJ := *.o

SRCDIR := ./src
INCDIR := ./includes
FTDIR := ./libft
FTINC := includes

SRC = *.c 
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
