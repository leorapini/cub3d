/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/04 12:18:00 by lpinheir         ###   ########.fr       */
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
	// FLOOR & CEILING - MOVE TO DRAW3D?
	int	x;
	int	y;

	x = 0;
	while (x < game->config.win_w)
	{
		y = 0;
		while (y < game->config.win_h / 2)
		{
			my_mlx_pixel_put(&game->img, x, y, game->config.ceiling_color);
			y++;
		}
		while (y < game->config.win_h)
		{
			my_mlx_pixel_put(&game->img, x, y, game->config.floor_color);
			y++;
		}
		x++;
	}

	// Load Texture
	//load_texture(game->config.no_texture, game);
	
	// Cast Rays & Draw 3d
	cast_rays(game);
}

void	load_texture(char *path, t_game *game)
{
	game->texture.img.img = mlx_xpm_file_to_image(game->mlx.mlx, path, 
			&game->texture.width, &game->texture.height);
	if (!(game->texture.img.img))
	{
		printf("bad error ptr 1\n");
		exit(1);
	}
	game->texture.img.addr = mlx_get_data_addr(game->texture.img.img,
			&game->texture.img.bits_per_pixel,
			&game->texture.img.line_length,
			&game->texture.img.endian);
	if (!(game->texture.img.addr))
	{
		printf("bad error ptr 2\n");
		exit(1);
	}
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
		while (y >= wall_top_pix && y < wall_bottom_pix)
		{
			if (game->ray.was_hit_ver)
				my_mlx_pixel_put(&game->img, x, y, GRAY);
			else
				my_mlx_pixel_put(&game->img, x, y, WHITE);
			y++;
		}
		y++;
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

int	setup_player_pos(t_player *player, t_config *config, int map[MAP_H][MAP_W])
{
	int	pix_x;
	int	pix_y;
	int	bl_h;
	int	bl_w;

	pix_y = 0;
	bl_h = 0;
	while (pix_y < config->win_h)
	{
		if ((pix_y == BLOCKSIZE && bl_h == 0)
			|| (pix_y % BLOCKSIZE == 0 && bl_h != 0))
			bl_h++;
		pix_x = 0;
		bl_w = 0;
		while (pix_x < config->win_w)
		{
			if ((pix_x == BLOCKSIZE && bl_w == 0)
				|| (pix_x % BLOCKSIZE == 0 && bl_w != 0))
				bl_w++;
			if (map[bl_h][bl_w] == USER)
			{
				player->x = pix_x + (BLOCKSIZE / 2);
				player->y = pix_y + (BLOCKSIZE / 2);
				//wall_hit(config);
				map[bl_h][bl_w] = FLOOR;
				return (0);
			}
			pix_x++;
		}
		pix_y++;
	}
	exit(1);
	return (1);
}
