/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:19:17 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/09 18:18:44 by lpinheir         ###   ########.fr       */
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
# define	CLNT_MSG_MASK	1L<<17

# define	MAP_W 200
# define	MAP_H 200
# define	BLOCKSIZE 64
# define	WIN_W 800
# define	WIN_H 600 

# define	ORANGE 16755200
# define	RED 16711680
# define	WHITE 16777215
# define	GRAY 8421504
# define	BLACK 0

# define	WALL 1
# define	FLOOR 8
# define	EMPTY 7
# define	END_LINE 888
# define	END_TABLE 999


# define	STEPS 2
# define	ANGLE 2

# define	PI 3.142857
# define	RADIAN PI / 180
# define	FOV 60.0 * (PI / 180.0)

// New Defines
# define	HALF_PI 0.5 * PI
# define	TWO_PI 2 * PI
# define	ONEFIVE_PI 1.5 * PI
# define	MOV_SPEED 3.0
# define	ROT_SPEED 3.0 * (PI / 180.0)

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
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
	int		floor_color;
	int		ceiling_color;
	int		map[MAP_H][MAP_W];
}		t_config;

typedef struct s_player
{
	float		x;
	float		y;
	int		turn_dir;
	int		walk_dir;
	double		rot_ang;
}		t_player;

typedef struct s_ray
{
	float		hit_x;
	float		hit_y;
	float		hit_dist;
	double		angle;
	int		hor_hit_y;
	int		hor_hit_x;
	int		hor_hit_cont;
	int		ver_hit_y;
	int		ver_hit_x;
	int		ver_hit_cont;
	int		found_hor_hit;
	int		found_ver_hit;
	double		hor_hit_dist;
	double		ver_hit_dist;
	int		was_hit_ver;
}		t_ray;

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

typedef struct s_texture
{
	t_data	img;
	int	width;
	int	height;
	int	offset_x;
	int	offset_y;
}		t_texture;

typedef struct	s_game
{
	t_mlx		mlx;
	t_config	config;
	t_data		img;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
}		t_game;

/* MAIN */
int	goodbye(t_game *game);

/* CONFIG */
void	init_player(t_player *player);
void	init_config(t_config *config);
void	init_ray(t_ray *ray);
void	init_texture(t_texture *texture);
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
int		check_map(int map[MAP_W][MAP_H]);

/* ML_CONFIG */
void	game_config(t_config config, t_player player, t_ray ray, t_texture texture, t_mlx *mlx, t_game *game, t_data *img);

/* CAMERA */
int	update_camera(t_game *game);

/* CONTROL */
void	update_map(t_game *game, int key);
int		key_control(int key, t_game *game);

/* ERROR HANDLING */
void	error(char *message);

/* DRAW  */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_game *game);
int		where_it_lands(t_config config, int new_x, int new_y);
int	setup_player_pos(t_player *player, int map[MAP_H][MAP_W]);
void	draw_3d(t_game *game, float col);
void	load_texture(char *path, t_game *game);

/* RAYCASTING */
void	cast_rays(t_game *game);
int	wall_hit(t_game *game);
int	hor_wall_hit(t_game *game);
int	ver_wall_hit(t_game *game);
double	norm_angle(double angle);

#endif
