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
#include "mlx.h"

/* Receives a line and config and iterates over each character assigning
the corresponding value to the map structure */
int	parse_map(char *line, t_config *config)
{
	int			x;
	static int	y = 0;

	x = 0;
	while (line[x] != 0)
	{
		if (line[x] == 'S' || line[x] == 'N' || line[x] == 'E'
			|| line[x] == 'W')
			config->map[y][x] = line[x];
		else if (line[x] == '1')
			config->map[y][x] = ft_ctoi(line[x]);
		else if (line[x] == '0')
			config->map[y][x] = FLOOR;
		else
			config->map[y][x] = EMPTY;
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
				error(".cub MAP ERROR - 0 is last row");
			if (map[y][x] == EMPTY && map[y - 1][x] == FLOOR)
				error(".cub MAP ERROR - space with with 0 above");
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
				error(".cub MAP ERROR - 0 in top row");
			if (map[y][x] == EMPTY && map[y + 1][x] == FLOOR)
				error(".cub MAP ERROR - empty space above 0");
			if (map[y][x] == FLOOR && x == 0)
				error(".cub MAP ERROR - 0 not precede by 1");
			if ((map[y][x] == FLOOR && map[y][x - 1] == EMPTY)
				|| (map[y][x] == FLOOR && map[y][x + 1] == EMPTY))
				error(".cub MAP ERROR - 0 with empty space");
			x++;
		}
		x = 0;
		y++;
	}
	y--;
	check_map_bottom(0, y, map);
}
