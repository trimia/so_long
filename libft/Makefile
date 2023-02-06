# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 13:12:30 by mmariani          #+#    #+#              #
#    Updated: 2023/01/29 19:14:03 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRIPT_AUTHOR = trimia

NAME = libft.a

INC=libft.h

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
	   ft_printstrmatrix.c	\
	   ft_freeintmatrix.c \
	   ft_freestrmatrix.c

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

OBJS_MAND = $(SRCS:.c=.o)
OBJS_BNS = $(OBJS_MAND) $(BONUS:.c=.o)

all:
	@$(MAKE) OBJS="$(OBJS_MAND)" $(NAME) 

bonus:
	@$(MAKE) OBJS="$(OBJS_BNS)" $(NAME) 

%.o:	%.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(INC)
	ar rcs libft.a $(OBJS)
	# ranlib $(NAME)

clean:
	rm -rf $(OBJS_MAND) $(OBJS_BNS)

fclean: clean
	rm -rf $(NAME)

re:		fclean all

.PHONY: all fclean re clean bonus