/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:23:58 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/10 14:13:23 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

/* Receives texture and game and sets x offset value (Function is called 
in draw_3d) */
void	texture_offset_x(t_texture *texture, t_game *game)
{
	if (game->ray.was_hit_ver)
		texture->offset_x = (int) game->ray.hit_y % texture->width;
	else
		texture->offset_x = (int) game->ray.hit_x % texture->width;
}

/* Receives texture, path to texture file and game and loads file to image 
through mlx_xpm_file_to_image. (Function is called in game_mlx_settings) */
void	load_texture(t_texture *texture, char *path, t_game *game)
{
	texture->img.img = mlx_xpm_file_to_image(game->mlx.mlx, path,
			&texture->width,
			&texture->height);
	if (!(texture->img.img))
		error("Bad texture img.img in load_texture()");
	texture->img.addr = mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel,
			&texture->img.line_length,
			&texture->img.endian);
	if (!(texture->img.addr))
		error("bad texture img.addr in load_texture()");
}

/* Receives texture, top of the wall pixel, wall height and y value and
returns color value according to correct offset values x and y. (Function is 
called in draw_3d) */
int	texture_color(t_texture *texture, int top_pix, int wall_height, int y)
{
	texture->offset_y = (y - top_pix) * ((float) texture->height / wall_height);
	return (*(unsigned int *)(texture->img.addr
		+ (texture->offset_y * texture->img.line_length
			+ texture->offset_x * (texture->img.bits_per_pixel / 8))));
}
