/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:19:17 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/09 09:44:25 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define	KEY_UP		65362
# define	KEY_DOWN	65364
# define	KEY_LEFT	65361
# define	KEY_RIGHT	65363
# define	KEY_ESC		65307

# define	KEY_PRESS	02
# define	KEY_PRESS_MASK	1L<<0
# define	CLIENT_MESSAGE	33
# define	CLNT_MSG_MASK	1L<<19

# define	MAP_W 24
# define	MAP_H 24

# define	BLOCK_W 64
# define	BLOCK_H 64

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
}		t_config;

typedef struct s_spr
{
	int	width;
	int	height;
	int	pos_x;
	int	pos_y;
	char	*texture;
	void	*ptr;
	t_mlx	mlx;
}		t_spr;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

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

/* ML_CONFIG */
void	mlx_config(t_config config, t_mlx *mlx);

/* CAMERA */
void	camera(t_spr *sprite);
void	start_spr(t_spr *sprite, t_mlx mlx, t_config config);
void	update_camera(t_spr sprite);

/* ERROR HANDLING */
void	error(char *message);

/* DRAW  */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_config config, t_data img, int color);

#endif
