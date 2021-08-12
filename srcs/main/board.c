/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:41:59 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 11:39:27 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives config, new x position and new y position and checks if 
it is located in the correct place in the board (FLOOR and not a WALL) */
int	is_not_a_wall(t_config config, float new_x, float new_y)
{
	int	bl_h;
	int	bl_w;

	bl_h = (int)floor(new_y / BLOCKSIZE);
	bl_w = (int)floor(new_x / BLOCKSIZE);
	if (config.map[bl_h][bl_w] == FLOOR)
		return (1);
	else
		return (0);
}


int	is_a_wall(t_config config, float new_x, float new_y)
{
	int	bl_h;
	int	bl_w;

	bl_h = (int)floor(new_y / BLOCKSIZE);
	bl_w = (int)floor(new_x / BLOCKSIZE);
	if (config.map[bl_h][bl_w] == WALL)
		return (1);
	else
		return (0);
}

/* Receives player and direction (letter in int format) and sets player 
rotation angle accordingly */
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
		error(".cub WRONG LETTER in map position ");
}

/* Receives player and map and sets player x and y positions */
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
	error("User not found on map");
	return (1);
}
