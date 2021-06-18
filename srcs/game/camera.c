/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:43:27 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/17 15:35:30 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	update_camera(t_game game)
{
	mlx_clear_window(game.mlx.mlx, game.mlx.win);
	draw_line(game, game.config.map);
	mlx_put_image_to_window(game.mlx.mlx, game.mlx.win, game.img.img, 0, 0);
}
