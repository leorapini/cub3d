/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:02:07 by lpinheir          #+#    #+#             */
/*   Updated: 2021/07/14 14:13:30 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	wall_hit(t_config *config)
{
	int	hor_hit_x;
	int	hor_hit_y;
	int	ver_hit_x;
	int	ver_hit_y;
	int	hit_hor;
	int	hit_ver;

	hor_wall_hit(config);
	hor_hit_x = config->hor_hit_x;
	hor_hit_y = config->hor_hit_y;

	ver_wall_hit(config);
	ver_hit_x = config->ver_hit_x;
	ver_hit_y = config->ver_hit_y;

	hit_hor = sqrt(pow((hor_hit_x - config->pos_x), 2) + 
			pow((hor_hit_y - config->pos_y), 2));
	hit_ver = sqrt(pow((ver_hit_x - config->pos_x), 2) + 
			pow((ver_hit_y - config->pos_y), 2));
	if (hit_hor < hit_ver)
	{
		config->hit_x = hor_hit_x;
		config->hit_y = hor_hit_y;
	}
	else
	{
		config->hit_x = ver_hit_x;
		config->hit_y = ver_hit_y;
	}
}

int	ver_wall_hit(t_config *config)
{	
	int	hit_y;
	int	hit_x;
	int	grid_y;
	int	grid_x;
	int	ya;
	int	xa;

	xa = BLOCKSIZE;
	ya = - (BLOCKSIZE * tan(config->angle));

	/* Add variation for if it is facing left */
	hit_x = (int) (config->pos_x / BLOCKSIZE) * (BLOCKSIZE) + BLOCKSIZE;
	grid_x = (int) hit_x / BLOCKSIZE;
	hit_y = config->pos_y + (config->pos_x - hit_x) * tan(config->angle);
	grid_y = (int) hit_y / BLOCKSIZE;
	while (config->map[grid_y][grid_x] == FLOOR)
	{
		hit_x = hit_x + xa;
		hit_y = hit_y + ya;
		if (hit_y < 0)
			hit_y = 0;
		grid_x = (int) hit_x / BLOCKSIZE;
		grid_y = (int) hit_y / BLOCKSIZE;
	}
	config->ver_hit_x = hit_x;
	config->ver_hit_y = hit_y;
	return (0);
}

int	hor_wall_hit(t_config *config)
{
	int	hit_y;
	int	hit_x;
	int	grid_y;
	int	grid_x;
	int	ya;
	int	xa;

	xa = BLOCKSIZE / tan(config->angle);
	ya = -BLOCKSIZE;

	/* Add variation for if it is facing up - hit_y */
	hit_y = (int) (config->pos_y / BLOCKSIZE) * (BLOCKSIZE) - 1;
	grid_y = hit_y / BLOCKSIZE;
	hit_x = config->pos_x + (config->pos_y - hit_y) / tan(config->angle);
	grid_x = hit_x / BLOCKSIZE;
	while (config->map[grid_y][grid_x] == FLOOR)
	{
		hit_x = hit_x + xa;
		hit_y = hit_y + ya;
		grid_x = hit_x / BLOCKSIZE;
		grid_y = hit_y / BLOCKSIZE;
	}
	config->hor_hit_x = hit_x;
	config->hor_hit_y = hit_y;
	return (0);
}
