/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/02 20:03:02 by lpinheir         ###   ########.fr       */
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

void	draw(t_game *game, int map[MAP_H][MAP_W])
{
	/*
	int	x;
	int	y;
	int bl_w;
	int bl_h;

	// Draw Board
	y = 0;
	while (y < game->config.win_h)
	{
		x = 0;
		while (x < game->config.win_w)
		{
			bl_w = x / BLOCKSIZE;
			bl_h = y / BLOCKSIZE;
			if (map[bl_h][bl_w] == FLOOR)
				my_mlx_pixel_put(&game->img, x, y, WHITE);
			else if (map[bl_h][bl_w] == WALL || map[bl_h][bl_w] == PILLAR)
				my_mlx_pixel_put(&game->img, x, y, ORANGE);
			x++;
		}
		y++;
	}

	// Player
	my_mlx_pixel_put(&game->img, game->player.x, game->player.y, RED);
	my_mlx_pixel_put(&game->img, game->player.x+1, game->player.y, RED);
	my_mlx_pixel_put(&game->img, game->player.x+1, game->player.y+1, RED);
	my_mlx_pixel_put(&game->img, game->player.x, game->player.y+1, RED);
	*/

	printf("%d\n", map[0][0]);
	// Cast Rays
	cast_rays(game);

}

void	draw_3d(t_game *game, float col)
{
	float	dist_proj_plane;
	float	proj_wall_height;
	int	wall_height;
	int	wall_top_pix;
	int	wall_bottom_pix;
	float	x;
	float	y;

	x = col;
	y = 0;

	dist_proj_plane = (game->config.win_w / 2) / tan(FOV / 2);
	proj_wall_height = (BLOCKSIZE / game->ray.hit_dist) * dist_proj_plane;
	wall_height = (int) proj_wall_height;

	wall_top_pix = (game->config.win_h / 2) - (wall_height / 2);
	if (wall_top_pix < 0)
		wall_top_pix = 0;

	wall_bottom_pix = (game->config.win_h / 2) + (wall_height / 2);
	if (wall_bottom_pix > game->config.win_h)
		wall_bottom_pix = game->config.win_h; 
	
	//printf("wall_top_pix:%d wall_bottom_pix:%d\n", wall_top_pix, wall_bottom_pix);
	while (y < game->config.win_h)
	{
		while (y >= wall_top_pix && y < wall_bottom_pix)
		{
			//printf("Printing\n");
			my_mlx_pixel_put(&game->img, x, y, RED);
			y++;
		}
		my_mlx_pixel_put(&game->img, x, y, 0);
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
