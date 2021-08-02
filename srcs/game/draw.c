/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/07/30 19:55:50 by lpinheir         ###   ########.fr       */
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


	// Cast Rays
	cast_rays(game);
	
	// Final Hit 	
	//my_mlx_pixel_put(&game->img, game->ray.hit_x, game->ray.hit_y, RED);
	//my_mlx_pixel_put(&game->img, game->ray.hit_x+1, game->ray.hit_y, RED);
	//my_mlx_pixel_put(&game->img, game->ray.hit_x+1, game->ray.hit_y+1, RED);
	//my_mlx_pixel_put(&game->img, game->ray.hit_x, game->ray.hit_y+1, RED);
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
