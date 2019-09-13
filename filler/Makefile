# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:57:25 by hypark            #+#    #+#              #
#    Updated: 2019/09/13 12:48:49 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := hypark.filler
CC := gcc
CFLAGS := -Wall -Wextra -Wextra
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
	mkdir $(OBJECTS)
	mv *.o $(OBJECTS)

clean:
	$(MAKE) -sC $(FTDIR) clean
	rm -f $(OBJECTS)/$(OBJ)
	rm -r $(OBJECTS)

fclean: clean
	$(MAKE) -sC $(FTDIR) fclean
	rm -f $(NAME)

re: fclean all
