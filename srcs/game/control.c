/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:40:27 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 14:25:08 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

/* Receives game, angle and step values and updates player position on
the board structure */
static void	update_position(t_game *game, float angle, int step)
{
	int		new_y;
	int		new_x;

	new_x = game->player.x + (int)(cos(game->player.rot_ang + angle) * step);
	new_y = game->player.y + (int)(sin(game->player.rot_ang + angle) * step);
	if (is_not_a_wall(game->config, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
		if (game->player.x == BLOCKSIZE)
			game->player.x += 2;
		if (game->player.y == BLOCKSIZE)
			game->player.y += 2;
	}
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
}

/* Receives game and key value and adjusts players direction and angle */
void	update_direction(t_game *game, int key)
{
	int		step;
	float	angle;

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
	game->player.rot_ang = game->player.rot_ang
		+ game->player.turn_dir * ROT_SPEED;
	game->player.rot_ang = norm_angle(game->player.rot_ang);
	step = game->player.walk_dir * MOV_SPEED;
	if (key == KEY_A || key == KEY_D)
		angle = HALF_PI;
	else
		angle = 0;
	update_position(game, angle, step);
}

/* Receives int value of key pressed and game and calls updates map 
function with according to key. At the end, calls update_camera */
int	key_control(int key, t_game *game)
{
	if (key == KEY_ESC)
		goodbye(game);
	else if (key == KEY_A)
		update_direction(game, KEY_A);
	else if (key == KEY_D)
		update_direction(game, KEY_D);
	else if (key == KEY_W)
		update_direction(game, KEY_W);
	else if (key == KEY_S)
		update_direction(game, KEY_S);
	else if (key == KEY_LEFT)
		update_direction(game, KEY_LEFT);
	else if (key == KEY_RIGHT)
		update_direction(game, KEY_RIGHT);
	update_camera(game);
	return (0);
}
