/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:43:27 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/08 14:44:51 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	start_spr(t_spr *sprite, t_mlx mlx, t_config config)
{
	sprite->width = 50;
	sprite->height = 50;
	sprite->pos_x = (config.win_w/2) - (sprite->width/2);
	sprite->pos_y = (config.win_h/2) - (sprite->height/2);
	sprite->texture = config.spr_texture; 
	sprite->ptr = mlx_xpm_file_to_image(mlx.mlx, sprite->texture,
			&sprite->width, &sprite->height);
	sprite->mlx = mlx;
}

void	update_camera(t_spr sprite) 
{
	mlx_clear_window(sprite.mlx.mlx, sprite.mlx.win);
	mlx_put_image_to_window(sprite.mlx.mlx, sprite.mlx.win, sprite.ptr, 
			sprite.pos_x, sprite.pos_y);
}

void	camera(t_spr *sprite)
{
	mlx_put_image_to_window(sprite->mlx.mlx, sprite->mlx.win, sprite->ptr,
			sprite->pos_x, sprite->pos_y);
}
