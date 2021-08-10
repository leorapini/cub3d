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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	update_camera(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx.mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx.mlx, game->config.win_w,
					game->config.win_h);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
				&game->img.line_length, &game->img.endian);	
	cast_rays(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	return (0);
}

void	draw_3d(t_game *game, float col)
{
	float	dist_proj_plane;
	float	proj_wall_height;
	float	perp_dist;
	int	wall_height;
	int	wall_top_pix;
	int	wall_bottom_pix;
	float	x;
	float	y;
	int	color;
	t_texture	*texture;

	x = col;
	y = 0;

	perp_dist = game->ray.hit_dist * cos(game->ray.angle - game->player.rot_ang);
	dist_proj_plane = (game->config.win_w / 2) / tan(FOV / 2);
	proj_wall_height = (BLOCKSIZE / perp_dist) * dist_proj_plane;
	wall_height = (int) proj_wall_height;

	wall_top_pix = (game->config.win_h / 2) - (wall_height / 2);
	if (wall_top_pix < 0)
		wall_top_pix = 0;

	wall_bottom_pix = (game->config.win_h / 2) + (wall_height / 2);
	if (wall_bottom_pix > game->config.win_h)
		wall_bottom_pix = game->config.win_h; 
	
	while (y < game->config.win_h)
	{
		while (y < wall_top_pix)
		{
			my_mlx_pixel_put(&game->img, x, y, game->config.ceiling_color);
			y++;
		}
		while (y >= wall_top_pix && y < wall_bottom_pix)
		{	
			if (game->ray.was_hit_ver)
			{
				if (!(game->ray.angle < HALF_PI
					|| game->ray.angle > ONEFIVE_PI))
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
			texture_offset_x(texture, game);
			color = texture_color(texture, wall_top_pix, wall_height, y);
			my_mlx_pixel_put(&game->img, x, y, color);
			y++;
		}
		while (y < game->config.win_h)
		{
			my_mlx_pixel_put(&game->img, x, y, game->config.floor_color);
			y++;
		}
	}
}

