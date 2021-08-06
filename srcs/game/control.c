/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:40:27 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/06 17:29:49 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	update_map(t_game *game, int key)
{
	int	new_y;
	int	new_x;
	int	step;
	float	angle;

	new_y = game->player.y;
	new_x = game->player.x;
	if (key == KEY_A)
		game->player.walk_dir = -1;
	else if (key == KEY_D)
		game->player.walk_dir = 1;
	else if (key == KEY_W)
		game->player.walk_dir = 1;
	else if (key == KEY_S)
		game->player.walk_dir = -1;
	else if (key == KEY_LEFT)
		game->player.turn_dir = -1;
	else if (key == KEY_RIGHT)
		game->player.turn_dir = 1;
	game->player.rot_ang = game->player.rot_ang + game->player.turn_dir * 
				ROT_SPEED;
	game->player.rot_ang = norm_angle(game->player.rot_ang);
	step = game->player.walk_dir * MOV_SPEED;
	if (key == KEY_A || key == KEY_D)
		angle = PI / 2;
	else
		angle = 0;
	new_x = new_x + (int) (cos(game->player.rot_ang + angle) * step);
	new_y = new_y + (int) (sin(game->player.rot_ang + angle) * step); 
	if (where_it_lands(game->config, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
}

int	key_control(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_A)
		update_map(game, KEY_A);
	else if (key == KEY_D)
		update_map(game, KEY_D);
	else if (key == KEY_W)
		update_map(game, KEY_W);
	else if (key == KEY_S)
		update_map(game, KEY_S);
	else if (key == KEY_LEFT)
		update_map(game, KEY_LEFT);
	else if (key == KEY_RIGHT)
		update_map(game, KEY_RIGHT);
	else
		printf("%d pressed\n", key);
	update_camera(*game);
	return (0);
}
