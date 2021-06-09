/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/09 09:48:22 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *
				(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw(t_config config, t_data img, int color)
{
	int	win_h;
	int	win_w;

	if (config.win_h < BLOCK_H)
		exit(1);
	win_w = 0;
	while (win_w <= BLOCK_W)
	{
		win_h = 0;
		while (win_h <= BLOCK_H)
		{
			my_mlx_pixel_put(&img, win_w, win_h, color);
			win_h++;
		}
		win_w++;
	}
}
