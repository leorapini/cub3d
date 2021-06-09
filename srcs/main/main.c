/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/09 09:51:46 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

static int	key_hook(int key)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_LEFT)
		;
	else if (key == KEY_RIGHT)
		;
	else
		printf("Key was pressed!\n");
	return (key);
}

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
	t_data	img;
	int	pos_x;
	int	pos_y;

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
	mlx_config(config, &mlx);
	img.img = mlx_new_image(mlx.mlx, config.win_w, config.win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw(config, img, config.floor_color);
	pos_x = config.win_w / 2;
	pos_y = config.win_h / 2;
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, pos_x, pos_y);
	mlx_hook(mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, &mlx);
	mlx_hook(mlx.win, CLIENT_MESSAGE, CLNT_MSG_MASK, goodbye, &mlx);
	mlx_loop(mlx.mlx);
	free_config(&config);
	return (0);
}
