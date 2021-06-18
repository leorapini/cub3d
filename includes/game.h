/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:19:17 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/18 10:39:01 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define	KEY_UP		65362
# define	KEY_DOWN	65364
# define	KEY_LEFT	65361
# define	KEY_RIGHT	65363
# define	KEY_ESC		65307
# define	KEY_W		119
# define	KEY_A		97
# define	KEY_S		115
# define	KEY_D		100

# define	KEY_PRESS	02
# define	KEY_PRESS_MASK	1L<<0
# define	CLIENT_MESSAGE	33
# define	CLNT_MSG_MASK	1L<<19

# define	MAP_W 200
# define	MAP_H 200
# define	BLOCKSIZE 28

# define	ORANGE 16755200
# define	RED 16711680
# define	WHITE 16777215

# define	WALL 1
# define	PILLAR 2
# define	FLOOR 8
# define	USER 9
# define	EMPTY 7

# define	STEPS 2

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}		t_mlx;

typedef struct s_config
{
	int		win_h;
	int		win_w;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*spr_texture;
	int		floor_color;
	int		ceiling_color;
	int		map[MAP_H][MAP_W];
	int		pos_x;
	int		pos_y;
}		t_config;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_w;
	int		size_h;
	int		color;
	int		pos_x;
	int		pos_y;
}		t_data;

typedef struct	s_game
{
	t_mlx		mlx;
	t_config	config;
	t_data		img;
}		t_game;

/* CONFIG */
void	init_config(t_config *config);
void	check_config(t_config config);
void	free_config(t_config *config);

/* PARSER */
int		parse_cub(char const *file, t_config *config);

/* PARSER UTILS */
void	free_split(char **words_line);
int		rgb_to_int(char *rgb_color);
int		check_file_exists(char const *file);

/* PARSE MAP */
int		parse_map(char *line, t_config *config);

/* ML_CONFIG */
void	game_config(t_config config, t_mlx *mlx, t_game *game, t_data *img);

/* CAMERA */
void	update_camera(t_game game);

/* CONTROL */
void	update_map(t_game *game, int key);
int		key_control(int key, t_game *game);

/* ERROR HANDLING */
void	error(char *message);

/* DRAW  */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_game game, int map[MAP_H][MAP_W]);
int		where_it_lands(t_config config, int new_x, int new_y);
int		setup_player_pos(t_config *config, int map[MAP_H][MAP_W]);

/* RAYCASTING */
int	ray_length(t_config config, int map[MAP_H][MAP_W]);

#endif
