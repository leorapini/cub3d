/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:02:07 by lpinheir          #+#    #+#             */
/*   Updated: 2021/07/30 20:12:40 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static double	hit_distance(int h_x, int h_y, int p_x, int p_y)
{
	double distance;
	
	distance = sqrt(pow((double)(h_x - p_x), 2) + pow((double)(h_y - p_y), 2));
	return (distance);
}

static double	norm_angle(double angle)
{
	double	l_angle;

	l_angle = fmod(angle, (2 * PI));
	if (l_angle < 0)
		l_angle = (2 * PI) + angle;
	return (l_angle);
}

void	cast_rays(t_game *game)
{
	int	col;
	int	strip_width;
	int	num_rays;


	strip_width = 1;
	num_rays = game->config.win_w / strip_width;	
	col = 0;

	// First Ray
	game->ray.angle = game->player.rot_ang - (FOV / 2);
	game->ray.angle = norm_angle(game->ray.angle);
	//game->ray.angle = game->player.rot_ang; // DELETE THIS AFTER TESTS
	//printf("ORG RAY:%f\n", game->ray.angle);
	game->ray.angle = norm_angle(game->ray.angle);
	//printf("NORM RAY:%f\n", game->ray.angle);
	while (col < game->config.win_w)
	{
		//printf("RAY:%d ANG:%f\n", col, ray_ang);
		wall_hit(game);
		my_mlx_pixel_put(&game->img, game->ray.hit_x, game->ray.hit_y, RED);
		my_mlx_pixel_put(&game->img, game->ray.hit_x+1, game->ray.hit_y, RED);
		my_mlx_pixel_put(&game->img, game->ray.hit_x+1, game->ray.hit_y+1, RED);
		my_mlx_pixel_put(&game->img, game->ray.hit_x, game->ray.hit_y+1, RED);	
		game->ray.angle = game->ray.angle + FOV / num_rays;
		col++;
	}

	// Draw hit
	//my_mlx_pixel_put(&game->img, game->ray.hit_x, game->ray.hit_y, RED);	
	//my_mlx_pixel_put(&game->img, game->ray.hit_x+1, game->ray.hit_y, RED);
	//my_mlx_pixel_put(&game->img, game->ray.hit_x+1, game->ray.hit_y+1, RED);
	//my_mlx_pixel_put(&game->img, game->ray.hit_x, game->ray.hit_y+1, RED);	
}

int	wall_hit(t_game *game)
{
	hor_wall_hit(game);
	ver_wall_hit(game);
	if (game->ray.hor_hit_dist < game->ray.ver_hit_dist)
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
	return (0);
}

int	ver_wall_hit(t_game *game)
{
	int	hit_y;
	int	hit_x;
	int	x_step;
	int	y_step;
	int	p_x;
	int	p_y;
	double	r_ang;
	
	p_x = game->player.x;
	p_y = game->player.y;
	r_ang = game->ray.angle;

	hit_x = (int) ((p_x / BLOCKSIZE)) * BLOCKSIZE;
	if (r_ang < 0.5 * PI || r_ang > 1.5 * PI) // facing right
		hit_x = hit_x + BLOCKSIZE;
	hit_y = p_y + (hit_x - p_x) * tan(r_ang);
	if (hit_y > game->config.win_h)
		hit_y = game->config.win_h - 1;
	if (hit_y < 0)
		hit_y = 0;
	
	// Calculate x_step and y_step
	x_step = BLOCKSIZE;	
	if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI)) // facing left
		x_step = x_step * -1;
	else
		x_step = x_step * 1; // facing right
	y_step = BLOCKSIZE * tan(r_ang);
	if (!(r_ang > 0 && r_ang < PI) && (y_step > 0)) // facing up
		y_step = y_step * -1;
	else if (!(r_ang > 0 && r_ang < PI) && (y_step < 0)) // facing up
		y_step = y_step * 1;
	else if ((r_ang > 0 && r_ang < PI) && (y_step < 0)) // facing down
		y_step = y_step * -1;
	else
		y_step = y_step * 1;	
	
	// Calculate Hits
	if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI)) // facing left
		hit_x--;
	
	while ((hit_x >= 0 && hit_x < game->config.win_w) && (hit_y >= 0
		&& hit_y < game->config.win_h))
	{
		if (!(where_it_lands(game->config, hit_x, hit_y)))
			break ;
		else
		{
			hit_x = hit_x + x_step;
			hit_y = hit_y + y_step;
			if (hit_y > game->config.win_h)
				hit_y = game->config.win_h - 1;
			if (hit_y < 0)
				hit_y = 0;
		}
	}
	game->ray.ver_hit_x = hit_x;
	game->ray.ver_hit_y = hit_y;
	game->ray.ver_hit_dist = hit_distance(hit_x, hit_y, p_x, p_y);
	return (0);
}

int	hor_wall_hit(t_game *game)
{
	int	hit_y;
	int	hit_x;
	int	x_step;
	int	y_step;
	int	p_x;
	int	p_y;
	double	r_ang;
	
	p_x = game->player.x;
	p_y = game->player.y;
	r_ang = game->ray.angle;

	hit_y = (int) ((p_y / BLOCKSIZE)) * BLOCKSIZE;
	if (r_ang > 0 && r_ang < PI)
		hit_y = hit_y + BLOCKSIZE;
	hit_x = p_x + (hit_y - p_y) / tan(r_ang);

	// Calculate x_step and y_step
	y_step = BLOCKSIZE;	
	if (!(r_ang > 0 && r_ang < PI)) // facing up
		y_step = y_step * -1;
	else
		y_step = y_step * 1; // facing down
	x_step = BLOCKSIZE / tan(r_ang);
	if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI) && (x_step > 0))
		x_step = x_step * -1;
	else if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI) && (x_step < 0))
		x_step = x_step * 1;
	else if ((r_ang < 0.5 * PI || r_ang > 1.5 * PI) && (x_step < 0))
		x_step = x_step * -1;
	else
		x_step = x_step * 1;	
	
	// Calculate Hits
	if (!(r_ang > 0 && r_ang < PI)) // facing up
		hit_y--;
	
	while ((hit_x >= 0 && hit_x < game->config.win_w) && (hit_y >= 0
		&& hit_y < game->config.win_h))
	{
		if (!(where_it_lands(game->config, hit_x, hit_y)))
			break ;
		else
		{
			hit_x = hit_x + x_step;
			hit_y = hit_y + y_step;
		}
	}
	game->ray.hor_hit_x = hit_x;
	game->ray.hor_hit_y = hit_y;
	game->ray.hor_hit_dist = hit_distance(hit_x, hit_y, p_x, p_y);
	return (0);
}
