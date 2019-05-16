# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerelo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 18:18:49 by smerelo           #+#    #+#              #
#    Updated: 2018/05/07 18:30:53 by smerelo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRCS = fract_ol.c\
	   interactive.c\
	   init_var.c\
	   color.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C libft
			gcc -o $(NAME) $(OBJS) -Iusr/local/inculde -Ilibft libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
%.o: %.c
		gcc $(CFLAGS) -c $<
clean:
		make clean -C libft
			rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
