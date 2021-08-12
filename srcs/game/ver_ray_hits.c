/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_ray_hits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:27:40 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 11:32:35 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives angle and calculates y_step value based on the angle (pointing
up or down) and if y_step is positive or negative*/
static float	ver_y_step(double r_ang)
{
	float	y_step;

	y_step = BLOCKSIZE * tan(r_ang);
	if (!(r_ang > 0 && r_ang < PI) && (y_step > 0))
		y_step = y_step * -1;
	else if (!(r_ang > 0 && r_ang < PI) && (y_step < 0))
		y_step = y_step * 1;
	else if ((r_ang > 0 && r_ang < PI) && (y_step < 0))
		y_step = y_step * -1;
	else
		y_step = y_step * 1;
	return (y_step);
}

/* Receives angle and calculates x_step value based on the angle (pointing
left or right) */
static float	ver_x_step(double r_ang)
{
	float	x_step;

	x_step = BLOCKSIZE;
	if (!(r_ang < HALF_PI || r_ang > ONEFIVE_PI))
		x_step = x_step * -1;
	else
		x_step = x_step * 1;
	return (x_step);
}

/* Receives angle and hit_x and returns a x value based on the angle (if
it is poiting left or right)*/
static float	x(double r_ang, float hit_x)
{
	if (!(r_ang < HALF_PI || r_ang > ONEFIVE_PI))
		return (hit_x - 1);
	else
		return (hit_x);
}

/* Receives game, hit_x and hit_y and sets the according values to game->ray */
static void	ver_set_hit(t_game *game, float hit_x, float hit_y)
{
	game->ray.ver_hit_x = hit_x;
	game->ray.ver_hit_y = hit_y;
	if (game->ray.ver_hit_x == game->player.x && game->ray.ver_hit_y
		== game->player.y)
	{
		game->ray.ver_hit_x += 2;
		game->ray.ver_hit_y += 2;
	}
	game->ray.found_ver_hit = 1;
	game->ray.was_hit_ver = 1;
}

/* Receives game and finds the first hits based on the player positions and
angle. It then uses y_step and x_step to keep increasing ray length until 
a wall is found. Note that a "temporary" x is used to check if a wall is
hit: x(angle, current_hit_x) */
void	ver_wall_hit(t_game *game)
{
	float	hit_y;
	float	hit_x;
	float	x_step;
	float	y_step;

	hit_x = floor((game->player.x / BLOCKSIZE)) * BLOCKSIZE;
	if (game->ray.angle < 0.5 * PI || game->ray.angle > 1.5 * PI)
		hit_x = hit_x + BLOCKSIZE;
	hit_y = game->player.y + (hit_x - game->player.x) * tan(game->ray.angle);
	x_step = ver_x_step(game->ray.angle);
	y_step = ver_y_step(game->ray.angle);
	while ((hit_x >= 0 && hit_x < game->config.win_w) && (hit_y >= 0
			&& hit_y < game->config.win_h))
	{
		if (is_a_wall(game->config, x(game->ray.angle, hit_x), hit_y))
		{
			ver_set_hit(game, hit_x, hit_y);
			break ;
		}
		else
		{
			hit_x = hit_x + x_step;
			hit_y = hit_y + y_step;
		}
	}
}
