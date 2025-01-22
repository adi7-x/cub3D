# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 17:16:06 by adbourji          #+#    #+#              #
#    Updated: 2025/01/22 18:27:46 by adbourji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c    ft_calloc.c ft_isalpha.c ft_isdigit.c ft_memchr.c \
	   ft_memcpy.c  ft_memset.c ft_strdup.c ft_strlcpy.c ft_strncmp.c \
	   ft_strrchr.c ft_toupper.c ft_bzero.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_memcmp.c ft_memmove.c ft_strchr.c ft_strlcat.c \
	   ft_strlen.c  ft_strnstr.c ft_tolower.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_strsrch.c ft_strcmp.c ft_whitespace.c ft_split1.c \


OBJS = $(SRCS:.c=.o)

HFILES = libft.h

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $?


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
