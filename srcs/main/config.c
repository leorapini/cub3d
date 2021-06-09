/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:15:43 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/08 15:47:53 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives config address and initializes it with starting values*/
void	init_config(t_config *config)
{
	config->win_h = 0;
	config->win_w = 0;
	config->no_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->ea_texture = NULL;
	config->spr_texture = NULL;
	config->floor_color = 0;
	config->ceiling_color = 0;
}

/* Receives config and checks if values are equal to initialized 
values and calls error function if true. Meaning they weren't 
properly set up. */
void	check_config(t_config config)
{
	if (config.win_h == 0 || config.win_w == 0)
		error("Missing Resolution values");
	else if (config.no_texture == NULL)
		error("Missing North Texture");
	else if (config.so_texture == NULL)
		error("Missing South Texture");
	else if (config.we_texture == NULL)
		error("Missing West Texture");
	else if (config.ea_texture == NULL)
		error("Missing East Texture");
	else if (config.spr_texture == NULL)
		error("Missing Sprite Texture");
	else if (config.floor_color == 0)
		error("Missing Floor Color");
	else if (config.ceiling_color == 0)
		error("Missing Ceiling Color");
}

/* Receibes config address and frees memory appointed to each 
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
	if (config->spr_texture != NULL)
		free(config->spr_texture);
}
