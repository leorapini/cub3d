/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/09 18:41:54 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

int	goodbye(t_game *game)
{
	printf("Goodbye!\n");
	free_config(&game->config);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_mlx		mlx;
	t_data		img;
	t_game		game;
	t_player	player;
	t_ray		ray;
	t_texture	texture;

	init_config(&config);
	init_player(&player);
	init_ray(&ray);
	init_texture(&texture);
	if (argc < 2)
		parse_cub("./maps/1.cub", &config);
	else if (argc == 2)
		parse_cub(argv[1], &config);
	else if (argc == 3)
		error("Not implemented");
	else
		error("Too many arguments");
	check_config(config);
	check_map(config.map);
	setup_player_pos(&player, config.map);
	game_config(config, player, ray, texture, &mlx, &game, &img);
	load_texture(config.no_texture, &game);
	update_camera(&game);
	mlx_loop_hook(game.mlx.mlx, update_camera, &game);
	mlx_hook(game.mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_control, &game);
	mlx_hook(game.mlx.win, CLIENT_MESSAGE, CLNT_MSG_MASK, goodbye, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
