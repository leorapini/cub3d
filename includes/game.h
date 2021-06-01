/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:19:17 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/01 19:10:57 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define	KEY_UP		65362
# define	KEY_DOWN	65364
# define	KEY_LEFT	65361
# define	KEY_RIGHT	65363
# define	KEY_ESC		65307

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_config
{
	int		win_h;
	int		win_w;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*spr_texture;
	int		floor_color;
	int		ceiling_color;	
}		t_config;

/* CONFIG */
void	init_config(t_config *config);
void	free_config(t_config *config);

/* PARSER */
int		parse_cub(char const *file, t_config *config);

/* PARSER UTILS */
void	free_split(char **words_line);
int		rgb_to_int(char *rgb_color);

#endif
