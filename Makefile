# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 14:56:57 by gmorra            #+#    #+#              #
#    Updated: 2020/12/27 16:43:48 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

HEADERS = includes/ft_libft.h\
		includes/ft_manage.h\
		includes/ft_parser.h\
		includes/libftprintf.h\

CC = gcc

SRC = ft_printf.c\
	parsers/ft_parser_main.c parsers/ft_parser_utils.c\
	src/libft_first.c src/libft_second.c\
	src/int_manage.c\
	src/arr_manage.c\
	src/hex_manage.c\
	src/ptr_manage.c\
	src/uns_manage.c\
	src/manage_functions.c\
	src/malloc_count.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJ} ${HEADERS}
	ar rc ${NAME} ${OBJ} ${HEADERS}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
