# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 14:56:57 by gmorra            #+#    #+#              #
#    Updated: 2020/12/20 19:38:31 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

HEADER = includes/libftprintf.h

OPTION = -c -I $(HEADER)

CC = gcc

SRC = ft_printf.c\
	parsers/ft_parser_main.c parsers/ft_parser_utils.c\
	src/libft_first.c src/libft_second.c\
	src/manage_functions.c\
	src/int_manage_first.c src/int_manage_second.c\
	src/arr_manage_first.c src/arr_manage_second.c\
	src/malloc_count.c\
	src/hex_manage_first.c src/hex_manage_second.c\
	src/uns_manage_first.c src/uns_manage_second.c\

COMPILE = gcc -g -Wall -Wextra -Werror ft_printf.c main.c src/*.c parsers/*.c && ./a.out

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJ}
	ar rc $(NAME) $(OBJ)

COMPILE:
	${COMPILE}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
