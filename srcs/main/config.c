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

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->rot_ang = 0;
}

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

void	init_texture(t_texture *texture)
{
	texture->width = 32;
	texture->height = 32;
	texture->offset_x = 0;
	texture->offset_y = 0;
}

/* Receives config and checks if values are equal to initialized 
values and calls error function if true. Meaning they weren't 
properly set up. */
void	check_config(t_config config)
{
	if (config.no_texture == NULL)
		error("Missing North Texture");
	else if (config.so_texture == NULL)
		error("Missing South Texture");
	else if (config.we_texture == NULL)
		error("Missing West Texture");
	else if (config.ea_texture == NULL)
		error("Missing East Texture");
	else if (config.floor_color == 0)
		error("Missing Floor Color");
	else if (config.ceiling_color == 0)
		error("Missing Ceiling Color");
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
