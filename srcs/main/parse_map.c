/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:49:54 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/09 11:51:26 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

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

int	check_map(int map[MAP_W][MAP_H])
{
	int 	x;
	int	y;
	int	first_floor;
	int	last_floor;
	int	first_row;
	int	last_row;

	first_floor = 0;
	last_floor = 0;
	first_row = 1;
	last_row = 1;
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
	x = 0;
	while (map[y][x] != END_TABLE)
	{
		while(map[y][x] != END_LINE)
		{
			if (map[y][x] == FLOOR)
				error(".cub MAP ERROR - 0 is last row");
			if (map[y][x] == EMPTY && map[y - 1][x] == FLOOR)
				error(".cub MAP ERROR - 0 with with space above");
			x++;
		}
		x = 0;
		y++;	
	}	
	return (0);
}
