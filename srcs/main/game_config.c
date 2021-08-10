/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:49:24 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/10 13:55:37 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	game_config(t_config config, t_player player, t_ray ray, t_mlx *mlx, t_game *game, t_data *img)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, config.win_w, config.win_h, "Cub3d");
	img->img = mlx_new_image(mlx->mlx, config.win_w, config.win_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->size_w = BLOCKSIZE * MAP_W;
	img->size_h = BLOCKSIZE * MAP_H;
	img->color = config.floor_color;
	game->mlx = *mlx;
	game->config = config;
	game->player = player;
	game->ray = ray;
	game->img = *img;
	load_texture(&game->texture, game->config.no_texture, game);
	load_texture(&game->no_texture, game->config.no_texture, game);
	load_texture(&game->we_texture, game->config.we_texture, game);
	load_texture(&game->ea_texture, game->config.ea_texture, game);
	load_texture(&game->so_texture, game->config.so_texture, game);
}
