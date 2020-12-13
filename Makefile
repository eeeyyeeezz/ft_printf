# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 14:56:57 by gmorra            #+#    #+#              #
#    Updated: 2020/12/13 16:49:06 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = libftprintf.h

CC = gcc

FLAGS = -Wall -Wextra -Werror



clean:

fclean: clean


.PHONY: all clean fclean re
