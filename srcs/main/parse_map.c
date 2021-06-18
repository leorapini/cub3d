/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:49:54 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/17 15:54:25 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

/* WALL = 1 / PILLAR = 2 / FLOOR = 8 / USER = 9 / EMPTY = 7 */
int	parse_map(char *line, t_config *config)
{
	int			x;
	static int	y = 0;

	x = 0;
	while (line[x] != 0)
	{
		if (ft_isalpha(line[x]) && line[x] != ' ')
			config->map[y][x] = USER;
		else if (line[x] == '1' || line[x] == '2')
			config->map[y][x] = ft_ctoi(line[x]);
		else if (line[x] == '0')
			config->map[y][x] = FLOOR;
		else
			config->map[y][x] = EMPTY;
		x++;
	}
	y++;
	return (0);
}
