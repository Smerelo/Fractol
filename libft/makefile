# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerelo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 23:21:22 by smerelo           #+#    #+#              #
#    Updated: 2018/04/26 00:25:02 by smerelo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SRCS = ft_isdigit.c ft_strcpy.c  ft_strncat.c ft_tolower.c\
ft_isalnum.c ft_isprint.c ft_strdup.c  ft_strncmp.c ft_toupper.c\
ft_isalpha.c ft_strcat.c  ft_strlcat.c ft_strncpy.c ft_isascii.c\
ft_strcmp.c ft_strlen.c ft_strstr.c ft_isdigit.c ft_strchr.c ft_strrchr.c\
ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
ft_memcmp.c ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putendl.c ft_putstr_fd.c\
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strclr.c ft_striter.c ft_strequ.c\
ft_strnequ.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_memalloc.c ft_memdel.c\
ft_strnew.c ft_strdel.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
ft_strtrim_2.c ft_strsplit.c ft_atoi.c ft_strnstr.c ft_strjoin2.c\
ft_tablen.c\

Header = libft.h
OBJ = $(SRCS:.c=.o)
all: $(NAME)
$(NAME):
	gcc -Wall -Werror -Wextra -c -I $(HEADER) $(SRCS)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all
