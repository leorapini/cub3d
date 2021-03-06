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

/* Receives game and sets mlx settings and loads textures */
void	game_mlx_settings(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!(game->mlx.mlx))
		error("Error in mlx_init");
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->config.win_w,
			game->config.win_h, "Cub3d | lpinheir");
	if (!(game->mlx.win))
		error("Error in mlx_new_window");
	game->img.img = mlx_new_image(game->mlx.mlx, game->config.win_w,
			game->config.win_h);
	if (!(game->img.img))
		error("Error in mlx_new_image");
	load_texture(&game->no_texture, game->config.no_texture, game);
	load_texture(&game->we_texture, game->config.we_texture, game);
	load_texture(&game->ea_texture, game->config.ea_texture, game);
	load_texture(&game->so_texture, game->config.so_texture, game);
}

/* Receives config and checks if values are equal to initialized 
values and calls error function if true. Meaning they weren't 
properly set up. */
void	check_config(t_config config)
{
	if (config.no_texture == NULL)
		error(".cub file misconfiguration");
	else if (config.so_texture == NULL)
		error(".cub file misconfiguration");
	else if (config.we_texture == NULL)
		error(".cub file misconfiguration");
	else if (config.ea_texture == NULL)
		error(".cub file misconfiguration");
	else if (config.floor_color == -1)
		error(".cub file misconfiguration");
	else if (config.ceiling_color == -1)
		error(".cub file misconfiguration");
}

/* Receives config address and frees memory appointed to each 
of the config items */
void	free_config(t_config *config)
{
	if (config->no_texture != NULL)
		free(config->no_texture);
	if (config->so_texture != NULL)
		free(config->so_texture);
	if (config->we_texture != NULL)
		free(config->we_texture);
	if (config->ea_texture != NULL)
		free(config->ea_texture);
}
