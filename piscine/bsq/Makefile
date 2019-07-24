# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hule <hule@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 16:08:45 by hule              #+#    #+#              #
#    Updated: 2018/06/06 22:39:49 by hule             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar

NAME    := bsq
LIB     := libft.a
SRCDIR  := srcs
INCDIR  := includes
SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard *.c)
HEADERS := $(wildcard $(INCDIR)/*.h) $(wildcard *.h)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
LIBOBJS := $(addprefix $(SRCDIR)/,\
	ft_atoi.o ft_putchar.o ft_putchar_err.o ft_putnbr.o ft_putnbr_err.o \
	ft_putstr.o ft_putstr_err.o ft_strcmp.o ft_strlen.o ft_swap.o ft_strcat.o)

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: CFLAGS += -DDEBUG -g
debug: re

%.o: %.c
	$(CC) -c $(CFLAGS) -I$(INCDIR) $< -o $@

$(LIB): $(LIBOBJS)
	$(AR) rcs $@ $^

$(NAME): util.c header.c lifecycle.c io.c inner.c $(NAME).c main.c
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

.PHONY: clean
clean:
	-rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	-rm -f $(NAME) $(LIB)

.PHONY: re
re: fclean all

.PHONY: norm
norm: $(SOURCES) $(HEADERS)
	@norminette $^

.PHONY: test
test: all
	./runtests
