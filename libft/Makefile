# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 21:11:28 by lpinheir          #+#    #+#              #
#    Updated: 2021/06/10 18:23:42 by lpinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC_FLAGS = -Wall -Wextra -Werror
AR_FLAGS = -rcs
RM_FLAGS = -f

CC = gcc

S_DIR = srcs
SRC = $(S_DIR)/ft_atoi.c	\
	$(S_DIR)/ft_bzero.c	\
	$(S_DIR)/ft_calloc.c	\
	$(S_DIR)/ft_isalnum.c	\
	$(S_DIR)/ft_isalpha.c	\
	$(S_DIR)/ft_isascii.c	\
	$(S_DIR)/ft_isdigit.c	\
	$(S_DIR)/ft_isprint.c	\
	$(S_DIR)/ft_itoa.c	\
	$(S_DIR)/ft_memccpy.c	\
	$(S_DIR)/ft_memchr.c	\
	$(S_DIR)/ft_memcmp.c	\
	$(S_DIR)/ft_memcpy.c	\
	$(S_DIR)/ft_memmove.c	\
	$(S_DIR)/ft_memset.c	\
	$(S_DIR)/ft_putchar_count.c \
	$(S_DIR)/ft_putchar_fd.c \
	$(S_DIR)/ft_putendl_fd.c \
	$(S_DIR)/ft_putnbr_fd.c	 \
	$(S_DIR)/ft_putstr_count_limit.c \
	$(S_DIR)/ft_putstr_fd.c	\
	$(S_DIR)/ft_split.c		\
	$(S_DIR)/ft_strchr.c	\
	$(S_DIR)/ft_strdup.c	\
	$(S_DIR)/ft_strjoin.c	\
	$(S_DIR)/ft_strlcat.c	\
	$(S_DIR)/ft_strlcpy.c	\
	$(S_DIR)/ft_strlen.c	\
	$(S_DIR)/ft_strmapi.c   \
	$(S_DIR)/ft_strncmp.c	\
	$(S_DIR)/ft_strnstr.c	\
	$(S_DIR)/ft_strrchr.c	\
	$(S_DIR)/ft_strtrim.c 	\
	$(S_DIR)/ft_substr.c	\
	$(S_DIR)/ft_tolower.c	\
	$(S_DIR)/ft_toupper.c	\
	$(S_DIR)/ft_uitoh.c     \
	$(S_DIR)/ft_utoa.c 		\
	$(S_DIR)/get_next_line.c	\
	$(S_DIR)/ft_htoui.c	\
	$(S_DIR)/ft_strisdigit.c	\
	$(S_DIR)/ft_ctoi.c	\

O_DIR = objs
OBJ = $(patsubst $(S_DIR)/%.c, $(O_DIR)/%.o, $(SRC)) 


all:	$(NAME)

$(NAME):	$(OBJ)
	ar $(AR_FLAGS) $@ $^	

$(O_DIR)/%.o:	$(S_DIR)/%.c
	$(CC)	$(C_FLAGS) -I includes -c $< -o $@


re:	fclean all

fclean:	clean
	rm $(RM_FLAGS) $(NAME) 

clean:
	rm $(RM_FLAGS) $(OBJ)

