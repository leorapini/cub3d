# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 09:16:41 by lpinheir          #+#    #+#              #
#    Updated: 2021/08/17 16:50:50 by lpinheir         ###   ########.fr        #
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
MAIN = main
GAME = game

SRCS = $(S_DIR)/$(MAIN)/board.c $(S_DIR)/$(MAIN)/game_config.c 			\
		$(S_DIR)/$(MAIN)/inits.c $(S_DIR)/$(MAIN)/main.c 		\
		$(S_DIR)/$(MAIN)/parse_map.c $(S_DIR)/$(MAIN)/parser.c 		\
		$(S_DIR)/$(MAIN)/parser_utils.c					\
		$(S_DIR)/$(MAIN)/parse_colors_util.c				\
		$(S_DIR)/$(GAME)/control.c $(S_DIR)/$(GAME)/draw.c 		\
		$(S_DIR)/$(GAME)/hor_ray_hits.c $(S_DIR)/$(GAME)/raycasting.c 	\
		$(S_DIR)/$(GAME)/textures.c $(S_DIR)/$(GAME)/ver_ray_hits.c 	\

OBJS = $(subst $(S_DIR), $(O_DIR), $(SRCS:.c=.o))

$(O_DIR)/%.o:	$(S_DIR)/%.c
	@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)	

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm $(RM_FLAGS) $(OBJS)

fclean:	clean
	@make fclean -C $(LIBFT_DIR)
	@rm $(NAME)

re:	fclean all



