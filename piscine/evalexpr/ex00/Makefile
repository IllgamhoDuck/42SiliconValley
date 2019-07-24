# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 23:27:34 by hypark            #+#    #+#              #
#    Updated: 2018/06/03 03:55:34 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
SRC = srcs/eval_expr.c \
	  srcs/eval_expr_str.c \
	  srcs/eval_expr_data_structure.c \
	  srcs/eval_expr_cal.c \
	  srcs/eval_expr_print.c \
	  srcs/eval_expr_copy.c 

OBJ = eval_expr.o \
	  eval_expr_str.o \
	  eval_expr_data_structure.o \
	  eval_expr_cal.o \
	  eval_expr_print.o \
	  eval_expr_copy.o

$(NAME): all

all:
	$(CC) -c $(CFLAGS) $(SRC) -I$(INC_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
