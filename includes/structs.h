/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:48:58 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 10:57:59 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int			turn_dir;
	int			walk_dir;
	double		rot_ang;
}		t_player;

typedef struct s_ray
{
	float		hit_x;
	float		hit_y;
	float		hit_dist;
	double		angle;
	float		hor_hit_y;
	float		hor_hit_x;
	float		ver_hit_y;
	float		ver_hit_x;
	int			found_hor_hit;
	int			found_ver_hit;
	double		hor_hit_dist;
	double		ver_hit_dist;
	int			was_hit_ver;
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
	int		width;
	int		height;
	int		offset_x;
	int		offset_y;
}		t_texture;

typedef struct s_game
{
	t_mlx		mlx;
	t_config	config;
	t_data		img;
	t_player	player;
	t_ray		ray;
	float		column;
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
}		t_game;

#endif
