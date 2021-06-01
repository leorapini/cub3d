/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/01 08:55:32 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char **argv)
{
	t_config	config;

	init_config(&config);
	if (argc < 2)
	{
		parse_cub("./maps/1.cub", &config);
		printf("WIN_W: %d\n", config.win_w);
		printf("WIN_H: %d\n", config.win_h);
		printf("NO_TEXTURE: %s\n", config.no_texture);
		printf("SO_TEXTURE: %s\n", config.so_texture);
		printf("WE_TEXTURE: %s\n", config.we_texture);
		printf("EA_TEXTURE: %s\n", config.ea_texture);
		printf("SPR_TEXTURE: %s\n", config.spr_texture);
		printf("F: %d\n", config.floor_color);
		printf("C: %d\n", config.ceiling_color);
		free_config(&config);
		return (0);
	}
	parse_cub(argv[1], &config);
	return (0);
}
