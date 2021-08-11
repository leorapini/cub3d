/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:02:07 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/10 14:01:22 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static float	hit_distance(float h_x, float h_y, float p_x, float p_y)
{
	float	distance;

	distance = sqrt(pow((double)(h_x - p_x), 2) + pow((double)(h_y - p_y), 2));
	return (distance);
}

double	norm_angle(double angle)
{
	double	l_angle;

	l_angle = remainder(angle, (2 * PI));
	if (l_angle < 0)
		l_angle = (2 * PI) + l_angle;
	return (l_angle);
}

void	cast_rays(t_game *game)
{
	float	col;
	float	strip_width;
	float	num_rays;

	strip_width = 1;
	num_rays = game->config.win_w / strip_width;
	col = 0;
	game->ray.angle = game->player.rot_ang - (FOV / 2);
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
