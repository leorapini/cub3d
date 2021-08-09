/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:43:27 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/09 18:30:16 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

int	update_camera(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx.mlx, game->config.win_w,
					game->config.win_h);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
				&game->img.line_length, &game->img.endian);	
	draw(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	return (0);
}
