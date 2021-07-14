/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:40:27 by lpinheir          #+#    #+#             */
/*   Updated: 2021/07/12 16:15:12 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	update_map(t_game *game, int key)
{
	int	new_y;
	int	new_x;
	int	new_hit_y;
	int	new_hit_x;

	new_y = game->config.pos_y;
	new_x = game->config.pos_x;
	new_hit_y = game->config.hit_y;
	new_hit_x = game->config.hit_x;
	if (key == KEY_A)
	{
		new_x = new_x - STEPS;
		if (where_it_lands(game->config, new_x, new_y) == 1)
		{
			game->config.pos_x = new_x;
			wall_hit(&game->config);
		}
	}	
	else if (key == KEY_D)
	{
		new_x = new_x + STEPS;
		if (where_it_lands(game->config, new_x, new_y) == 1)
		{
			game->config.pos_x = new_x;
			wall_hit(&game->config);
		}
	}	
	else if (key == KEY_W)
	{
		new_y = new_y - STEPS;
		if (where_it_lands(game->config, new_x, new_y) == 1)
		{
			game->config.pos_y = new_y;
			wall_hit(&game->config);
		}
	}
	else if (key == KEY_S)
	{
		new_y = new_y + STEPS;
		if (where_it_lands(game->config, new_x, new_y) == 1)
		{
			game->config.pos_y = new_y;
			wall_hit(&game->config);
		}
	}
}

int	key_control(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_A)
	{
		update_map(game, KEY_A);
		update_camera(*game);
	}
	else if (key == KEY_D)
	{
		update_map(game, KEY_D);
		update_camera(*game);
	}
	else if (key == KEY_W)
	{
		update_map(game, KEY_W);
		update_camera(*game);
	}
	else if (key == KEY_S)
	{
		update_map(game, KEY_S);
		update_camera(*game);
	}
	else if (key == KEY_LEFT)
	{
		update_map(game, KEY_LEFT);
		update_camera(*game);
	}
	else if (key == KEY_RIGHT)
	{
		update_map(game, KEY_RIGHT);
		update_camera(*game);
	}
	else
		printf("%d pressed\n", key);
	return (0);
}
