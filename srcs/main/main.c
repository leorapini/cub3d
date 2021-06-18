/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/17 13:07:56 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

static int	goodbye(void)
{
	printf("Goodbye!\n");
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_mlx		mlx;
	t_data		img;
	t_game		game;

	init_config(&config);
	if (argc < 2)
		parse_cub("./maps/1.cub", &config);
	else if (argc == 2)
		parse_cub(argv[1], &config);
	else if (argc == 3)
		error("Not implemented");
	else
		error("Too many arguments");
	check_config(config);
	setup_player_pos(&config, config.map);
	game_config(config, &mlx, &game, &img);
	draw_line(game, config.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_control, &game);
	mlx_hook(mlx.win, CLIENT_MESSAGE, CLNT_MSG_MASK, goodbye, &game);
	mlx_loop(mlx.mlx);
	free_config(&config);
	return (0);
}
