/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/07/14 14:11:50 by lpinheir         ###   ########.fr       */
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

// calculate ray lengh. start at pos and move from there until hits wall 

void	draw_board(t_game game, int map[MAP_H][MAP_W])
{
	int	pix_x;
	int	pix_y;
	int	bl_h;
	int	bl_w;

	pix_y = 0;
	bl_h = 0;
	while (pix_y < game.config.win_h)
	{
		if ((pix_y == BLOCKSIZE && bl_h == 0)
			|| (pix_y % BLOCKSIZE == 0 && bl_h != 0))
			bl_h++;
		pix_x = 0;
		bl_w = 0;
		while (pix_x < game.config.win_w)
		{
			if ((pix_x == BLOCKSIZE && bl_w == 0)
				|| (pix_x % BLOCKSIZE == 0 && bl_w != 0))
				bl_w++;
			if (map[bl_h][bl_w] == WALL || map[bl_h][bl_w] == PILLAR)
				my_mlx_pixel_put(&game.img, pix_x, pix_y, ORANGE);
			else if (map[bl_h][bl_w] == FLOOR)
				my_mlx_pixel_put(&game.img, pix_x, pix_y, WHITE);
			pix_x++;
		}
		pix_y++;
	}
	/* User */
	my_mlx_pixel_put(&game.img, game.config.pos_x,
				game.config.pos_y, RED);
	/* Final Hit */
	my_mlx_pixel_put(&game.img, game.config.hit_x, game.config.hit_y, RED);
	
}


int	where_it_lands(t_config config, int new_x, int new_y)
{
	int	pix_x;
	int	pix_y;
	int	bl_h;
	int	bl_w;

	pix_y = 0;
	bl_h = 0;
	while (pix_y < config.win_h)
	{
		if ((pix_y == BLOCKSIZE && bl_h == 0)
			|| (pix_y % BLOCKSIZE == 0 && bl_h != 0))
			bl_h++;
		pix_x = 0;
		bl_w = 0;
		while (pix_x < config.win_w)
		{
			if ((pix_x == BLOCKSIZE && bl_w == 0)
				|| (pix_x % BLOCKSIZE == 0 && bl_w != 0))
				bl_w++;
			if (pix_x == new_x && pix_y == new_y)
			{
				if (config.map[bl_h][bl_w] == FLOOR)
					return (1);
				else
					return (0);
			}
			pix_x++;
		}
		pix_y++;
	}
	return (0);
}

int	setup_player_pos(t_config *config, int map[MAP_H][MAP_W])
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
				config->pos_x = pix_x + (BLOCKSIZE / 2);
				config->pos_y = pix_y + (BLOCKSIZE / 2);
				wall_hit(config);
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
