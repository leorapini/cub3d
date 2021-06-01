/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:15:43 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/27 16:16:32 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
