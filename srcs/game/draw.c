/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/10 14:34:27 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

/* Receives data (img), x and y positions and color (int) and puts pixels in
image before putting image to window */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* Receives game and destroys current image before creating a new one, 
casts rays and puts it to window */
int	update_camera(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx.mlx,
			game->config.win_w,
			game->config.win_h);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_length,
			&game->img.endian);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	return (0);
}

/* Receives game and checks ray angle to decide which texture to put to wall.
Returns pointer to selected texture */
static t_texture	*which_texture(t_game *game)
{
	t_texture	*texture;

	if (game->ray.was_hit_ver)
	{
		if (!(game->ray.angle < HALF_PI || game->ray.angle > ONEFIVE_PI))
			texture = &game->we_texture;
		else
			texture = &game->ea_texture;
	}
	else
	{
		if (!(game->ray.angle > 0 && game->ray.angle < PI))
			texture = &game->no_texture;
		else
			texture = &game->so_texture;
	}
	return (texture);
}

/* Receives game, wall height, wall top pixel and wall bottom pixel and
puts each pixel (row) in current column according to its location.
First loop puts ceilling color, middle loop puts wall and last loop puts
floor color */
static void	put_pixels(t_game *game, int wall_height, int top_pix,
	int bottom_pix)
{
	float		y;
	float		col;
	t_texture	*texture;
	int			color;

	y = -1;
	col = game->column;
	while (y++ < top_pix)
		my_mlx_pixel_put(&game->img, col, y, game->config.ceiling_color);
	while (y++ >= top_pix && y < bottom_pix)
	{
		texture = which_texture(game);
		texture_offset_x(texture, game);
		color = texture_color(texture, top_pix, wall_height, y);
		my_mlx_pixel_put(&game->img, col, y, color);
	}
	while (y++ < game->config.win_h)
		my_mlx_pixel_put(&game->img, col, y, game->config.floor_color);
}

/* Receives game and calculates the information needed to project wall
in the current column. Calls put_pixels once information is calculated */
void	draw_3d(t_game *game)
{
	float		dist_proj_plane;
	float		perp_dist;
	int			wall_height;
	int			wall_top_pix;
	int			wall_bottom_pix;

	perp_dist = game->ray.hit_dist
		* cos(game->ray.angle - game->player.rot_ang);
	dist_proj_plane = (game->config.win_w / 2) / tan(FOV / 2);
	wall_height = (int)((BLOCKSIZE / perp_dist) * dist_proj_plane);
	wall_top_pix = (game->config.win_h / 2) - (wall_height / 2);
	if (wall_top_pix < 0)
		wall_top_pix = 0;
	wall_bottom_pix = (game->config.win_h / 2) + (wall_height / 2);
	if (wall_bottom_pix > game->config.win_h)
		wall_bottom_pix = game->config.win_h;
	put_pixels(game, wall_height, wall_top_pix, wall_bottom_pix);
}
