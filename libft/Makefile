# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 13:12:30 by mmariani          #+#    #+#              #
#    Updated: 2022/12/14 16:57:34 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRIPT_AUTHOR = trimia

NAME = libft.a

SRCS = ft_isalpha.c		\
	   ft_isdigit.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_strlen.c		\
	   ft_memset.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memmove.c		\
	   ft_strlcpy.c		\
	   ft_strlcat.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_strchr.c		\
	   ft_strrchr.c		\
	   ft_strncmp.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strnstr.c		\
	   ft_atoi.c		\
	   ft_calloc.c		\
	   ft_strdup.c		\
	   ft_substr.c		\
	   ft_strjoin.c 	\
	   ft_strtrim.c 	\
	   ft_split.c		\
	   ft_itoa.c		\
	   ft_strmapi.c		\
	   ft_striteri.c	\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\
	   get_next_line.c	\
	   get_next_line_utils.c \
	   ft_printstrmatrix.c

OBJS = $(SRCS:.c=.o)

CC 		=	gcc

CFLAGS 	=	-Wall -Werror -Wextra -c

BONUS =	ft_lstnew.c			\
 		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c

OBJS_BONUS = $(BONUS:.c=.o)


all: $(NAME)

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS)

$(OBJS_BONUS):
	$(CC) $(CFLAGS) $(BONUS)

$(NAME): $(OBJS)
	ar rcs libft.a $(OBJS)
	# ranlib $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re:		fclean all

bonus: $(OBJS_BONUS)
	ar rcs libft.a $(OBJS_BONUS)


.PHONY: all fclean re clean bonus
