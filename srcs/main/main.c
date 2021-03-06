/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:19:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/12 09:55:42 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Exits game wihout error with a Goodbye message */
int	goodbye(t_game *game)
{
	printf("Goodbye!\n");
	free_config(&game->config);
	exit(0);
	return (0);
}

/* Receives a message, prints it, and exists with error */
void	error(char *message)
{
	printf("Error\n");
	printf(">> %s <<\n", message);
	exit(1);
}

/* Checks file name extension */
static void	is_dot_cub(char *file_name)
{
	char	*cub;
	int		len;
	int		j;

	cub = ft_strdup(".cub");
	len = ft_strlen(file_name) - 1;
	j = 3;
	while (j >= 0)
	{
		if (file_name[len] != cub[j])
		{
			free(cub);
			error("Wrong file extension");
		}
		j--;
		len--;
	}
	free(cub);
}

/* Main function */
int	main(int argc, char **argv)
{
	t_game		game;

	init_game(&game);
	if (argc < 2)
		error("Usage: ./cub3d ./maps/1.cub");
	else if (argc == 2)
	{
		is_dot_cub(argv[1]);
		parse_cub(argv[1], &game.config);
	}
	else
		error("Too many arguments. Usage: ./cub3d ./maps/1.cub");
	check_map(game.config.map);
	setup_player_pos(&game.player, game.config.map);
	game_mlx_settings(&game);
	update_camera(&game);
	mlx_loop_hook(game.mlx.mlx, update_camera, &game);
	mlx_hook(game.mlx.win, KEY_PRESS, 1L << 0, key_control, &game);
	mlx_hook(game.mlx.win, CLIENT_MESSAGE, 1L << 17, goodbye, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
