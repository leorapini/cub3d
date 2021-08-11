/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_ray_hits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:27:40 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/11 18:27:54 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ver_wall_hit(t_game *game)
{
	float	hit_y;
	float	hit_x;
	float	x_step;
	float	y_step;
	float	p_x;
	float	p_y;
	double	r_ang;
	
	p_x = game->player.x;
	p_y = game->player.y;
	r_ang = game->ray.angle;
	game->ray.found_ver_hit = 0;
	hit_x = floor((p_x / BLOCKSIZE)) * BLOCKSIZE;
	if (r_ang < 0.5 * PI || r_ang > 1.5 * PI)
		hit_x = hit_x + BLOCKSIZE;
	hit_y = p_y + (hit_x - p_x) * tan(r_ang);
	if (hit_y > game->config.win_h)
		hit_y = game->config.win_h - 1;
	if (hit_y < 0)
		hit_y = 0;
	x_step = BLOCKSIZE;	
	if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI))
	{
		x_step = x_step * -1;
	}
	else
	{
		x_step = x_step * 1;
	}
	y_step = BLOCKSIZE * tan(r_ang);
	if (!(r_ang > 0 && r_ang < PI) && (y_step > 0))
	{
		y_step = y_step * -1;
	}
	else if (!(r_ang > 0 && r_ang < PI) && (y_step < 0))
	{
		y_step = y_step * 1;
	}
	else if ((r_ang > 0 && r_ang < PI) && (y_step < 0))
	{
		y_step = y_step * -1;
	}
	else
	{
		y_step = y_step * 1;	
	}

	float	temp_x;

	temp_x = 0;
	while ((hit_x >= 0 && hit_x < game->config.win_w) && (hit_y >= 0
		&& hit_y < game->config.win_h))
	{
		if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI)) // facing left
			temp_x = hit_x - 1;
		else
			temp_x = hit_x;
		if (!(is_not_a_wall(game->config, temp_x, hit_y)))
		{
			game->ray.ver_hit_x = hit_x;
			game->ray.ver_hit_y = hit_y;
			game->ray.ver_hit_cont = 
				game->config.map[(int)floor(hit_y / BLOCKSIZE)][(int)floor(hit_x / BLOCKSIZE)];
			game->ray.found_ver_hit = 1;
			game->ray.was_hit_ver = 1;
			break ;
		}
		else
		{
			hit_x = hit_x + x_step;
			hit_y = hit_y + y_step;
		}
	}
	return (0);
}
