# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 23:36:24 by hypark            #+#    #+#              #
#    Updated: 2019/08/16 21:55:01 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a 
CC := gcc
CFLAGS := -Wall -Wextra -Werror

INCDIR := ./includes
LIBFT := ./src
PRINTF := ./printf

SRC := $(LIBFT)/*.c 
INCLUDES := -I$(INCDIR) 
OBJ := *.o $(PRINTF)/*.o

all: $(NAME)
.PHONY: all clean fclean re

$(NAME):
	$(MAKE) -sC $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(MAKE) -sC $(PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -sC $(PRINTF) fclean
	rm -f $(NAME)

re: fclean all

