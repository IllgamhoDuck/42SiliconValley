# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 21:17:49 by hypark            #+#    #+#              #
#    Updated: 2019/09/19 03:19:52 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in
CC := gcc
CFLAGS := -Wall -Wextra -Wextra -O3
OBJ := *.o

SRCDIR := ./src
INCDIR := ./includes
FTDIR := ./libft
FTINC := includes
OBJECTS := objects

SRC = $(SRCDIR)/*.c
INCLUDES := -I$(FTDIR)/$(FTINC) -I$(INCDIR) 
LIB := -L $(FTDIR) -lft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	$(MAKE) -sC $(FTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
	$(CC) $(LIB) $(OBJ) -o $@
	mv *.o $(OBJECTS)

clean:
	$(MAKE) -sC $(FTDIR) clean
	rm -f $(OBJECTS)/$(OBJ)

fclean: clean
	$(MAKE) -sC $(FTDIR) fclean
	rm -f $(NAME)

re: fclean all
