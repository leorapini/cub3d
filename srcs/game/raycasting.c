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
	float distance;
	
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

	// First Ray
	game->ray.angle = game->player.rot_ang - (FOV / 2);
	while (col < game->config.win_w)
	{
		game->column = col;
		game->ray.angle = norm_angle(game->ray.angle);
		wall_hit(game);
		draw_3d(game);
		game->ray.angle = game->ray.angle + FOV / num_rays;
		col++;
	}

}

int	wall_hit(t_game *game)
{
	hor_wall_hit(game);
	ver_wall_hit(game);
	
	game->ray.was_hit_ver = 0;	

	if (game->ray.found_hor_hit)
	{
		//printf("FOUND HOR HIT\n");
		game->ray.hor_hit_dist = hit_distance(game->ray.hor_hit_x,
				game->ray.hor_hit_y, game->player.x, game->player.y);
	}
	else
	{
		//printf("DID NOT FIND HOR HIT\n");
		game->ray.hor_hit_dist = (double) INT_MAX;
	}
	if (game->ray.found_ver_hit)
		game->ray.ver_hit_dist = hit_distance(game->ray.ver_hit_x,
				game->ray.ver_hit_y, game->player.x, game->player.y);
	else
		game->ray.ver_hit_dist = (double) INT_MAX;


	//printf("hor_dis:%f ver_dis:%f\n", game->ray.hor_hit_dist,
	//		game->ray.ver_hit_dist);

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
	return (0);
}

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
	{
		//printf("\nVER LEFT\n");
		x_step = x_step * -1;
	}
	else
	{
		//printf("\nVER RIGHT\n");
		x_step = x_step * 1; // facing right
	}
	y_step = BLOCKSIZE * tan(r_ang);
	if (!(r_ang > 0 && r_ang < PI) && (y_step > 0)) // facing up
	{
		//printf("VER UP\n");
		y_step = y_step * -1;
	}
	else if (!(r_ang > 0 && r_ang < PI) && (y_step < 0)) // facing up
	{
		//printf("VER UP\n");
		y_step = y_step * 1;
	}
	else if ((r_ang > 0 && r_ang < PI) && (y_step < 0)) // facing down
	{
		//printf("VER DOWN\n");
		y_step = y_step * -1;
	}
	else
	{
		//printf("VER DOWN\n");
		y_step = y_step * 1;	
	}
	
	// Calculate Hits
	//if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI)) // facing left
	//	hit_x--;
	
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

int	hor_wall_hit(t_game *game)
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
	game->ray.found_hor_hit = 0;

	hit_y = floor((p_y / BLOCKSIZE)) * BLOCKSIZE;
	if (r_ang > 0 && r_ang < PI) // Down
		hit_y = hit_y + BLOCKSIZE;
	hit_x = p_x + (hit_y - p_y) / tan(r_ang);

	//printf("\nr_ang:%f\n", r_ang);
	//printf("p_y:%f p_x:%f\n", p_y, p_x);
	//printf("orig hit_y:%f hit_x:%f\n", hit_y, hit_x);

	// Calculate x_step and y_step
	y_step = BLOCKSIZE;	
	if (!(r_ang > 0 && r_ang < PI)) // facing up
	{
		//printf("HOR UP\n");
		y_step = y_step * -1;
	}
	else
	{
		//printf("HOR DOWN\n");
		y_step = y_step * 1; // facing down
	}
	x_step = BLOCKSIZE / tan(r_ang);
	//printf("x_step:%f\n", x_step);
	if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI) && (x_step > 0)) // left
	{
		//printf("HOR LEFT\n");
		x_step = x_step * -1;
	}
	else if (!(r_ang < 0.5 * PI || r_ang > 1.5 * PI) && (x_step < 0))
	{
		//printf("HOR LEFT\n");
		x_step = x_step * 1;
	}
	else if ((r_ang < 0.5 * PI || r_ang > 1.5 * PI) && (x_step < 0))
	{
		//printf("HOR RIGHT\n");
		x_step = x_step * -1;
	}
	else
	{
		//printf("ELSE HOR RIGHT\n");
		x_step = x_step * 1;	
	}
	//printf("y_step:%f x_step:%f\n", y_step, x_step);
	// Calculate Hits
	//if (!(r_ang > 0 && r_ang < PI)) // facing up
	//	hit_y--;

	float temp_y;
	temp_y = 0;

		
	while ((hit_x >= 0 && hit_x < game->config.win_w) && (hit_y >= 0
		&& hit_y < game->config.win_h))
	{
		if (!(r_ang > 0 && r_ang < PI)) // facing up
			temp_y = hit_y - 1;
		else
		{
			//printf("FACE DOWN\n");
			temp_y = hit_y;
		}
		if (!(is_not_a_wall(game->config, hit_x, temp_y)))
		{
			game->ray.hor_hit_x = hit_x;
			game->ray.hor_hit_y = hit_y;
			game->ray.hor_hit_cont = 
				game->config.map[(int)floor(hit_y / BLOCKSIZE)][(int)floor(hit_x / BLOCKSIZE)];
			game->ray.found_hor_hit = 1;
			//printf("HIT FOUND\n");	
			break ;
		}
		else
		{
			hit_x = hit_x + x_step;
			hit_y = hit_y + y_step;
		}
	}
	//printf("final hit_y:%f hit_x:%f\n", hit_y, hit_x);
	return (0);
}
