# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hypark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 13:32:30 by hypark            #+#    #+#              #
#    Updated: 2019/09/04 05:54:16 by hypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ssl
CC := gcc
CFLAGS := -Wall -Wextra -Wextra -O3
OBJ := *.o

SRCDIR := ./src
INCDIR := ./includes
FTDIR := ./libft
FTINC := includes
OBJECTS := objects

MDC := mdc
MDCSRC := $(SRCDIR)/$(MDC)
MDCINC := $(INCDIR)/$(MDC)
MD5 := md5
SHA1 := sha1
SHA224 := sha224
SHA256 := sha256
SHA384 := sha384
SHA512 := sha512
SHA512_2 := sha512_2

CC := cc
CCSRC := $(SRCDIR)/$(CC)
CCINC := $(INCDIR)/$(CC)
BASE64 := base64
DES := des

SRC = $(SRCDIR)/*.c  $(MDCSRC)/*.c $(MDCSRC)/$(MD5)/*.c \
	  $(MDCSRC)/$(SHA1)/*.c  $(MDCSRC)/$(SHA224)/*.c  \
	  $(MDCSRC)/$(SHA256)/*.c  $(MDCSRC)/$(SHA384)/*.c \
	  $(MDCSRC)/$(SHA512)/*.c  $(MDCSRC)/$(SHA512_2)/*.c \
	  $(CCSRC)/*.c $(CCSRC)/$(BASE64)/*.c  $(CCSRC)/$(DES)/*.c
INCLUDES := -I$(FTDIR)/$(FTINC) -I$(INCDIR) -I$(MDCINC) -I$(CCINC) -I./
LIB := -L $(FTDIR) -lft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	$(MAKE) -sC $(FTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC) *.c
	$(CC) $(LIB) $(OBJ) -o $@
	mv *.o $(OBJECTS)

clean:
	$(MAKE) -sC $(FTDIR) clean
	rm -f $(OBJECTS)/$(OBJ)

fclean: clean
	$(MAKE) -sC $(FTDIR) fclean
	rm -f $(NAME)

re: fclean all
