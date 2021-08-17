/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:49:54 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/11 11:04:07 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives config, y and x positions and letter (c) with player position */
static void	check_and_set_player_pos(t_config *config, int y, int x, int c)
{
	if (config->found_player_dir == 0)
	{
		config->map[y][x] = c;
		config->found_player_dir = 1;
	}
	else
		error(".cub MAP ERROR");
}

/* Receives a line and config and iterates over each character assigning
the corresponding value to the map structure */
int	parse_map(char *lin, t_config *config)
{
	int			x;
	static int	y = 0;

	x = 0;
	while (lin[x] != 0)
	{
		if (lin[x] == 'S' || lin[x] == 'N' || lin[x] == 'E' || lin[x] == 'W')
			check_and_set_player_pos(config, y, x, lin[x]);
		else if (lin[x] == '1')
			config->map[y][x] = ft_ctoi(lin[x]);
		else if (lin[x] == '0')
			config->map[y][x] = FLOOR;
		else if (lin[x] == ' ')
			config->map[y][x] = EMPTY;
		else
			error(".cub MAP ERROR");
		x++;
	}
	config->map[y][x] = EMPTY;
	config->map[y][x + 1] = END_LINE;
	y++;
	config->map[y][0] = END_TABLE;
	return (0);
}

/* Receives x, y and map structure and iterates over it looking for possible
misconfigurations at the last row*/
static void	check_map_bottom(int x, int y, int map[MAP_W][MAP_H])
{
	while (map[y][x] != END_TABLE)
	{
		while (map[y][x] != END_LINE)
		{
			if (map[y][x] == FLOOR)
				error(".cub MAP ERROR");
			if (map[y][x] == EMPTY && map[y - 1][x] == FLOOR)
				error(".cub MAP ERROR");
			x++;
		}
		x = 0;
		y++;
	}
}

/* Receives map structure and iterates over it looking for possible
misconfigurations */
void	check_map(int map[MAP_W][MAP_H])
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x] != END_TABLE)
	{
		while (map[y][x] != END_LINE)
		{
			if (map[y][x] == FLOOR && y == 0)
				error(".cub MAP ERROR");
			if (map[y][x] == EMPTY && map[y + 1][x] == FLOOR)
				error(".cub MAP ERROR");
			if (map[y][x] == FLOOR && x == 0)
				error(".cub MAP ERROR");
			if ((map[y][x] == FLOOR && map[y][x - 1] == EMPTY)
				|| (map[y][x] == FLOOR && map[y][x + 1] == EMPTY))
				error(".cub MAP ERROR");
			x++;
		}
		x = 0;
		y++;
	}
	y--;
	check_map_bottom(0, y, map);
}
