/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_ray_hits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:21:29 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 11:32:57 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives angle and calculates y_step value based on the angle (pointing
up or down) */
static float	hor_y_step(double r_ang)
{
	float	y_step;

	y_step = BLOCKSIZE;
	if (!(r_ang > 0 && r_ang < PI))
		y_step = y_step * -1;
	else
		y_step = y_step * 1;
	return (y_step);
}

/* Receives angle and calculates x_step value based on the angle (pointing
left or right) and if x_step is negative or positive */
static float	hor_x_step(double r_ang)
{
	float	x_step;

	x_step = BLOCKSIZE / tan(r_ang);
	if (!(r_ang < HALF_PI || r_ang > ONEFIVE_PI) && (x_step > 0))
		x_step = x_step * -1;
	else if (!(r_ang < HALF_PI || r_ang > ONEFIVE_PI) && (x_step < 0))
		x_step = x_step * 1;
	else if ((r_ang < HALF_PI || r_ang > ONEFIVE_PI) && (x_step < 0))
		x_step = x_step * -1;
	else
		x_step = x_step * 1;
	return (x_step);
}

/* Receives angle and hit_y and returns a y value based on the angle (if
it is poiting up or down) */
static float	y(double r_ang, float hit_y)
{
	if (!(r_ang > 0 && r_ang < PI))
		return (hit_y - 1);
	else
		return (hit_y);
}

/* Receives game, hit_x and hit_y and sets the according values to game->ray */
static void	hor_set_hit(t_game *game, float hit_x, float hit_y)
{
	game->ray.hor_hit_x = hit_x;
	game->ray.hor_hit_y = hit_y;
	if (game->ray.hor_hit_x == game->player.x && game->ray.hor_hit_y
		== game->player.y)
	{
		game->ray.hor_hit_x += 2;
		game->ray.hor_hit_y += 2;
	}
	game->ray.found_hor_hit = 1;
}

/* Receives game and finds the first hits based on the player positions and
angle. It then uses y_step and x_step to keep increasing ray length until 
a wall is found. Note that a "temporary" y is used to check if a wall is
hit: y(angle, current_hit_y) */
void	hor_wall_hit(t_game *game)
{
	float	hit_y;
	float	hit_x;
	float	x_step;
	float	y_step;

	hit_y = floor((game->player.y / BLOCKSIZE)) * BLOCKSIZE;
	if (game->ray.angle > 0 && game->ray.angle < PI)
		hit_y = hit_y + BLOCKSIZE;
	hit_x = game->player.x + (hit_y - game->player.y) / tan(game->ray.angle);
	y_step = hor_y_step(game->ray.angle);
	x_step = hor_x_step(game->ray.angle);
	while ((hit_x >= 0 && hit_x < game->config.win_w) && (hit_y >= 0
			&& hit_y < game->config.win_h))
	{
		if (is_a_wall(game->config, hit_x, y(game->ray.angle, hit_y)))
		{
			hor_set_hit(game, hit_x, hit_y);
			break ;
		}
		else
		{
			hit_x = hit_x + x_step;
			hit_y = hit_y + y_step;
		}
	}
}
