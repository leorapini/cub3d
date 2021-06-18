/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:02:07 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/18 14:15:21 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

int	ray_length(t_config config, int map[MAP_H][MAP_W])
{
	int	pix_x;
	int	pix_y;
	int	bl_h;
	int	bl_w;
	int	ray_length;
	int	hit_h;
	int	hit_w;

	pix_y = 0;
	bl_h = 0;
	ray_length = 1;
	hit_h = 0;
	hit_w = 0;
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
			/* Checks if x line is the same, pos is "up" and if 
			it's a wall, if so, updates hit_h with the most recent
			hit and resets ray_length  */
			if ((pix_x == config.pos_x && pix_y < config.pos_y)
				&& map[bl_h][bl_w] == WALL)
			{
				if (hit_h == bl_h && hit_w == bl_w)
					;
				else
				{
					hit_h = bl_h;
					hit_w = bl_w;
					ray_length = 1;
				}
			}
			if ((pix_x == config.pos_x && pix_y < config.pos_y)
				&& map[bl_h][bl_w] == FLOOR)
				ray_length++;
			pix_x++;
		}
		pix_y++;
	}
	return (ray_length);
}
