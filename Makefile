# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 09:16:41 by lpinheir          #+#    #+#              #
#    Updated: 2021/05/24 11:15:37 by lpinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INCLUDES = -I includes -I $(LIBFT_DIR)/includes/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

MLX_DIR = minilibx-linux
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

CC = clang
CC_FLAGS = -Wall -Werror -Wextra

RM_FLAGS = -f

S_DIR = srcs
O_DIR = objs
SUBDIRS = main

S_DIRS = $(foreach dir, $(SUBDIRS), $(addprefix $(S_DIR)/, $(dir)))
O_DIRS = $(foreach dir, $(SUBDIRS), $(addprefix $(O_DIR)/, $(dir)))
SRCS = $(foreach dir, $(S_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(subst $(S_DIR), $(O_DIR), $(SRCS:.c=.o))

$(O_DIR)/%.o:	$(S_DIR)/%.c
	@mkdir -p $(O_DIR) $(O_DIRS)
	@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)	

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm $(RM_FLAGS) $(OBJS)
	@rm -r $(O_DIRS)

fclean:	clean
	@make fclean -C $(LIBFT_DIR)
	@rm $(NAME)

re:	fclean all



