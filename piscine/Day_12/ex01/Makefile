# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 20:05:46 by hypark            #+#    #+#              #
#    Updated: 2018/06/01 23:37:19 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat

$(NAME): all

all:
	$(CC) -c *.c
	$(CC) $(CFLAGS) -o $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
