# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:33:56 by mmariani          #+#    #+#              #
#    Updated: 2022/12/14 17:36:54 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -g 
# -Wall -Wextra -Werror
LINKS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS = solong.c makingthingsready.c map.c utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(LIBFT)
	$(CC) $(FLAGS) $(LINKS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
		make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re bonus