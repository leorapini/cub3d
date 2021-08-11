/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:15:43 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/06 16:16:07 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives game and initializes config, player and ray */
void	init_game(t_game *game)
{
	init_config(&game->config);
	init_player(&game->player);
	init_ray(&game->ray);
}

/* Receives config address and initializes it with starting values*/
void	init_config(t_config *config)
{
	config->win_h = WIN_H;
	config->win_w = WIN_W;
	config->no_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color = 0;
	config->ceiling_color = 0;
}

/* Receives player address and initializes it with starting values*/
void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->rot_ang = 0;
}

/* Receives ray address and initializes it with starting values*/
void	init_ray(t_ray *ray)
{
	ray->hit_x = 0;
	ray->hit_y = 0;
	ray->hit_dist = 0;
	ray->angle = 0;
	ray->hor_hit_y = 0;
	ray->hor_hit_x = 0;
	ray->ver_hit_y = 0;
	ray->ver_hit_x = 0;
	ray->found_hor_hit = 0;
	ray->found_ver_hit = 0;
	ray->was_hit_ver = 0;
}
