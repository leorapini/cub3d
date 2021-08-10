/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:41:59 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/10 14:42:25 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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