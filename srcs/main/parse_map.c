/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:49:54 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/06 18:23:33 by lpinheir         ###   ########.fr       */
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
	config->map[y][x] = END_LINE;
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
	first_row = 0;
	last_row = 0;
	y = 0;
	x = 0;
	while (map[y][x] != END_TABLE)
	{
		while (map[y][x] != END_LINE)
		{
			//printf("\nNEW LINE map[%d][%d]\n", y, x);
			if (map[y][x] == FLOOR)
			{
				printf("FOUND FLOOR\n");
			}
			x++;
		}
		x = 0;
		y++;		
	}	
	printf("END OF BOARD\n");
	return (0);
}
