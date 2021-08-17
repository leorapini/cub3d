/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:19:17 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 11:31:42 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "defines.h"
# include "structs.h"
# include "../minilibx-linux/mlx.h"

/* MAIN */
int		goodbye(t_game *game);
void	error(char *message);

/* INITS */
void	init_player(t_player *player);
void	init_config(t_config *config);
void	init_ray(t_ray *ray);
void	init_game(t_game *game);

/* PARSER */
int		parse_cub(char const *file, t_config *config);
void	parse_colors(char **words, char *line, int word_count,
			t_config *config);

/* PARSER UTILS */
void	free_split(char **words_line);
int		check_file_exists(char const *file);
int		words_counter(char **words);

/* PARSE COLORS UTILS */
void	line_rgb_to_int(int *config_color, char *line);
int		rgb_to_int(char *rgb_color);

/* PARSE MAP */
int		parse_map(char *line, t_config *config);
void	check_map(int map[MAP_W][MAP_H]);

/* GAME_CONFIG */
void	game_mlx_settings(t_game *game);
void	check_config(t_config config);
void	free_config(t_config *config);

/* CONTROL */
void	update_direction(t_game *game, int key);
int		key_control(int key, t_game *game);

/* BOARD */
int		setup_player_pos(t_player *player, int map[MAP_H][MAP_W]);
int		is_not_a_wall(t_config config, float new_x, float new_y);
int		is_a_wall(t_config config, float new_x, float new_y);

/* DRAW  */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_3d(t_game *game);
int		update_camera(t_game *game);

/* RAYCASTING */
void	cast_rays(t_game *game);
void	which_wall_hit(t_game *game);
double	norm_angle(double angle);

/* HOR RAY HITS */
void	hor_wall_hit(t_game *game);

/* VER RAY HITS */
void	ver_wall_hit(t_game *game);

/* TEXTURES */
void	load_texture(t_texture *texture, char *path, t_game *game);
void	texture_offset_x(t_texture *texture, t_game *game);
int		texture_color(t_texture *texture, int top_pix, int wall_height, int y);

#endif
