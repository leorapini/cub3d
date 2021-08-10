/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/10 14:34:27 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_game *game)
{
	// Cast Rays & Draw 3d
	cast_rays(game);
}

void	draw_3d(t_game *game, float col)
{
	float	dist_proj_plane;
	float	proj_wall_height;
	float	perp_dist;
	int	wall_height;
	int	wall_top_pix;
	int	wall_bottom_pix;
	float	x;
	float	y;
	int	color;
	t_texture	*texture;

	x = col;
	y = 0;

	perp_dist = game->ray.hit_dist * cos(game->ray.angle - game->player.rot_ang);
	dist_proj_plane = (game->config.win_w / 2) / tan(FOV / 2);
	proj_wall_height = (BLOCKSIZE / perp_dist) * dist_proj_plane;
	wall_height = (int) proj_wall_height;

	wall_top_pix = (game->config.win_h / 2) - (wall_height / 2);
	if (wall_top_pix < 0)
		wall_top_pix = 0;

	wall_bottom_pix = (game->config.win_h / 2) + (wall_height / 2);
	if (wall_bottom_pix > game->config.win_h)
		wall_bottom_pix = game->config.win_h; 
	
	while (y < game->config.win_h)
	{
		while (y < wall_top_pix)
		{
			my_mlx_pixel_put(&game->img, x, y, game->config.ceiling_color);
			y++;
		}
		while (y >= wall_top_pix && y < wall_bottom_pix)
		{	
			if (game->ray.was_hit_ver)
			{
				if (!(game->ray.angle < HALF_PI
					|| game->ray.angle > ONEFIVE_PI))
					texture = &game->we_texture;
				else
					texture = &game->ea_texture;
			}
			else
			{
				if (!(game->ray.angle > 0 && game->ray.angle < PI))
					texture = &game->no_texture;
				else
					texture = &game->so_texture;
			}
			texture_offset_x(texture, game);
			color = texture_color(texture, wall_top_pix, wall_height, y);
			my_mlx_pixel_put(&game->img, x, y, color);
			y++;
		}
		while (y < game->config.win_h)
		{
			my_mlx_pixel_put(&game->img, x, y, game->config.floor_color);
			y++;
		}
	}
}


int	where_it_lands(t_config config, int new_x, int new_y)
{
	int	bl_h;
	int	bl_w;

	bl_h = new_y / BLOCKSIZE;
	bl_w = new_x / BLOCKSIZE;
	if (config.map[bl_h][bl_w] == FLOOR)
		return (1);
	else
		return (0);
}

static void	set_ang(t_player *player, int dir)
{
	if (dir == 'S')
		player->rot_ang = HALF_PI;
	else if (dir == 'N')
		player->rot_ang = ONEFIVE_PI;
	else if (dir == 'E')
		player->rot_ang = TWO_PI;
	else if (dir == 'W') 
		player->rot_ang = PI;
	else
		error(".cub WRONG LETTER");
}

int	setup_player_pos(t_player *player, int map[MAP_H][MAP_W])
{
	int	bl_h;
	int	bl_w;

	bl_w = 0;
	while (bl_w < MAP_W)
	{
		bl_h = 0;
		while (bl_h < MAP_H)
		{
			if (map[bl_h][bl_w] == 'S' || map[bl_h][bl_w] == 'N'
				|| map[bl_h][bl_w] == 'E' || map[bl_h][bl_w] == 'W')
			{
				player->x = bl_w * BLOCKSIZE;
				player->y = bl_h * BLOCKSIZE;
				set_ang(player, map[bl_h][bl_w]); 
				map[bl_h][bl_w] = FLOOR;
				return (0);
			}
			bl_h++;
		}
		bl_w++; 
	}
	printf("User not found\n");
	return (1);
}
