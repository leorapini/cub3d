/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:02:07 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 08:55:07 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives hit x, hit y and players position x and y and calculates hit
distance */
static float	hit_distance(float h_x, float h_y, float p_x, float p_y)
{
	float	distance;

	distance = sqrt(pow((double)(h_x - p_x), 2) + pow((double)(h_y - p_y), 2));
	return (distance);
}

/* Receives angle and normalizes it */
double	norm_angle(double angle)
{
	double	l_angle;

	l_angle = remainder(angle, TWO_PI);
	if (l_angle < 0)
		l_angle = TWO_PI + l_angle;
	return (l_angle);
}

/* Receives game and iterates over each column casting rays checking for
horizontal hits and vertical hits by calling each respective function. 
Which wall hit is called to check which hit has a shorter distance, then
it calls draw_3d to actually draw each wall based on the current column
and the shorter hit */
void	cast_rays(t_game *game)
{
	float	col;
	float	strip_width;
	float	num_rays;

	strip_width = 1;
	num_rays = game->config.win_w / strip_width;
	col = 0;
	game->ray.angle = game->player.rot_ang - HALF_FOV;
	while (col < game->config.win_w)
	{
		game->column = col;
		game->ray.angle = norm_angle(game->ray.angle);
		game->ray.found_hor_hit = 0;
		hor_wall_hit(game);
		game->ray.found_ver_hit = 0;
		ver_wall_hit(game);
		game->ray.was_hit_ver = 0;
		which_wall_hit(game);
		draw_3d(game);
		game->ray.angle = game->ray.angle + FOV / num_rays;
		col++;
	}
}

/* Receives game and checks if ver and hor hits were found then decides
which one to use based on the shorter distance */
void	which_wall_hit(t_game *game)
{	
	if (game->ray.found_hor_hit)
	{
		game->ray.hor_hit_dist = hit_distance(game->ray.hor_hit_x,
				game->ray.hor_hit_y, game->player.x, game->player.y);
	}
	else
		game->ray.hor_hit_dist = (double) INT_MAX;
	if (game->ray.found_ver_hit)
		game->ray.ver_hit_dist = hit_distance(game->ray.ver_hit_x,
				game->ray.ver_hit_y, game->player.x, game->player.y);
	else
		game->ray.ver_hit_dist = (double) INT_MAX;
	if (game->ray.hor_hit_dist <= game->ray.ver_hit_dist)
	{
		game->ray.hit_x = game->ray.hor_hit_x;
		game->ray.hit_y = game->ray.hor_hit_y;
		game->ray.hit_dist = game->ray.hor_hit_dist;
	}
	else
	{
		game->ray.hit_x = game->ray.ver_hit_x;
		game->ray.hit_y = game->ray.ver_hit_y;
		game->ray.hit_dist = game->ray.ver_hit_dist;
		game->ray.was_hit_ver = 1;
	}
}
