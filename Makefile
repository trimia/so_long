# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:33:56 by mmariani          #+#    #+#              #
#    Updated: 2022/12/05 18:57:12 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -g 
# -Wall -Wextra -Werror
LINKS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
OBJ = minilibx.c
LIBFT = ./libft/libft.a

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME):$(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)
		make -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re bonus