# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 20:05:46 by hypark            #+#    #+#              #
#    Updated: 2018/05/30 21:45:09 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file

$(NAME): all

all:
	$(CC) -c *.c
	$(CC) $(CFLAGS) -o $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
