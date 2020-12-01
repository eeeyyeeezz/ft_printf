# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 16:39:14 by gmorra            #+#    #+#              #
#    Updated: 2020/11/09 14:03:56 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

OPTION = -c -I $(HEADER)

CC = gcc

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c	ft_isdigit.c\
	ft_isprint.c ft_itoa.c ft_memccpy.c	ft_memchr.c	ft_memcmp.c	ft_memcpy.c	ft_memmove.c\
	ft_memset.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
	ft_strchr.c	ft_strdup.c	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c	ft_substr.c	ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			 ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): ${OBJ}
	ar rc $(NAME) $(OBJ)

bonus: ${OBJ} ${OBJ_BONUS}
	ar rc $(NAME) $(OBJ) ${OBJ_BONUS}

clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
