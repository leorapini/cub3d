/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 07:24:21 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/24 17:17:26 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "window.h"

int	main(void)
{
	void	*mlx;
	void	*window_one;
	int	color;
//	void	*new_image;
	void	*cartoon;
	int	car_h;
	int	car_w;
	int	car_pos_x;
	int	car_pos_y;	

	car_h = 50;
	car_w = 50;

	/* Initializing MLX */
	mlx = mlx_init();
	if (!mlx)
	{
		printf("KO\n");
		return (1);
	}
	/* CREATE NEW WINDOW */
	window_one = mlx_new_window(mlx, WIN_W, WIN_H, "cub3d");
	if (!window_one)
	{
		printf("KO\n");
		return (1);
	}

	/* PIXEL & STRING PUT */
	color = 65280;	
	mlx_pixel_put(mlx, window_one, 50, 50, color);
	mlx_pixel_put(mlx, window_one, 55, 55, color);
	mlx_string_put(mlx, window_one, 70, 70, color, "Billy's Adventure");
	
	/* KEEP WINDOW OPEN */
	while (sleep(5) != 0)
		;

	/* CLEAR WINDOW */
	mlx_clear_window(mlx, window_one);

	/* XPM FILE TO IMAGE */
	cartoon = mlx_xpm_file_to_image(mlx, "./images/open.xpm", &car_w, &car_h);
	if (!cartoon)
	{
		printf("XPM KO\n");
		return (1);
	}
	car_pos_x = (WIN_W/2)-(car_w/2);
	car_pos_y = (WIN_H/2)-(car_h/2);

	/* KEEP WINDOW OPEN */
	while (car_pos_x > 0)
	{			
		mlx_put_image_to_window(mlx, window_one, cartoon, car_pos_x, car_pos_y);
		sleep(1);
		car_pos_x = car_pos_x - 10;
		car_w = car_w + 10;
		car_h = car_h + 10;
		mlx_clear_window(mlx, window_one);
	}
	//while (sleep(5) != 0)
	//	;
	//mlx_loop(mlx);
	
	/* DESTROY IMAGE */
	mlx_destroy_image(mlx, cartoon);	

	/* DESTROY WINDOW */
	mlx_destroy_window(mlx, window_one);

	/* RANDOM TESTS */
	printf("SUCCESS\n");

	return (0);
}
