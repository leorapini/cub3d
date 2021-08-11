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

/* Called in cast_rays */
void	texture_offset_x(t_texture *cur_texture, t_game *game)
{
	t_texture	*texture;

	texture = cur_texture;
	if (game->ray.was_hit_ver)
	{
		texture->offset_x = (int) game->ray.hit_y % texture->width;
	//	printf("offset:%d was vert\n", game->texture.offset_x);	
	}
	else
	{
		texture->offset_x = (int) game->ray.hit_x % texture->width;
	//	printf("offset:%d was hor\n", game->texture.offset_x);
	}
}

/* Called in game_config */
void	load_texture(t_texture *cur_texture, char *path, t_game *game)
{
	t_texture	*texture;

	texture = cur_texture;
	texture->img.img = mlx_xpm_file_to_image(game->mlx.mlx, path, 
			&texture->width, &texture->height);
	//printf("txt_w:%d txt_h:%d\n", texture->width, texture->height);
	if (!(texture->img.img))
	{
		printf("bad texture img.img\n");
		exit(1);
	}
	texture->img.addr = mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel,
			&texture->img.line_length,
			&texture->img.endian);
	if (!(texture->img.addr))
	{
		printf("bad teture img.addr\n");
		exit(1);
	}
}

/* Called in draw_3d */
int	texture_color(t_texture *texture, int top_pix, int wall_height, int y)
{
	texture->offset_y = (y - top_pix) * 
			((float) texture->height / wall_height);
	return (*(unsigned int *)(texture->img.addr + (texture->offset_y *
			texture->img.line_length + texture->offset_x *
			(texture->img.bits_per_pixel / 8))));
}
