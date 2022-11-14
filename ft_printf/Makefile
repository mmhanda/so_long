# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 21:03:34 by mhanda            #+#    #+#              #
#    Updated: 2022/02/12 21:03:36 by mhanda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_putchar.c \
			ft_puthexa.c \
			ft_putnbr.c \
			ft_putnbru.c \
			ft_putprt.c \
			ft_putstr.c \
			ft_printf.c
			
INCLUDE = ft_printf.h

OBJECTS =$(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(INCLUDE)
		ar rcs $(NAME) $(OBJECTS)
	
clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -f $(NAME)

re : fclean all
			