# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 03:37:01 by mhanda            #+#    #+#              #
#    Updated: 2022/02/11 13:16:16 by mhanda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC := cc
CFLAGS := -Wall -Werror -Wextra
LINKS := -lmlx -framework OpenGL -framework AppKit
PRINTF = ft_printf/libftprintf.a
CFILES := so_long.c window.c so_long_utils.c so_long_utils_1.c so_long_utils_2.c window_mb_utl.c window_utl_1.c window_utl_2.c
BCFILES := so_long_b.c window_b.c so_long_utils.c  so_long_utils_1.c so_long_utils_2.c window_mb_utl.c window_b_utl_1.c window_b_utl_2.c window_b_utl_3.c
 
OFILES := $(CFILES:.c=.o)
BOFILES := $(BCFILES:.c=.o)


INC := so_long.h


NAME := so_long
BNAME := so_long_b


$(NAME) : $(OFILES) $(INC) $(PRINTF)
	@$(CC) $(FLAGS) $(CFILES) $(PRINTF) $(LINKS) -o $(NAME)
$(BNAME) : $(BOFILES) $(INC) $(PRINTF)
	@$(CC) $(CFLAGS) $(BCFILES) $(PRINTF) $(LINKS) -o $(BNAME)

$(PRINTF):
	make -C ft_printf

all : $(NAME)
bonus : $(BNAME)
clean :
	@rm -rf $(OFILES)
	@rm -rf $(BOFILES)
	make -C ft_printf clean
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BNAME)
	make -C ft_printf fclean

re : fclean all
reb : fclean bonus