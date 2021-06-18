/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:34:04 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/10 18:03:52 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Parses Textures for SO, SO, WE, EA, S. Receives string with file location
and config and set those locations to each respective item in config */
static int	parse_textures(char *name, char *file_location, t_config *config)
{
	if (!file_location || !name)
		return (1);
	check_file_exists(file_location);
	if (!(ft_strncmp(name, "NO", 2)))
		config->no_texture = ft_strdup(file_location);
	else if (!(ft_strncmp(name, "SO", 2)))
		config->so_texture = ft_strdup(file_location);
	else if (!(ft_strncmp(name, "WE", 2)))
		config->we_texture = ft_strdup(file_location);
	else if (!(ft_strncmp(name, "EA", 2)))
		config->ea_texture = ft_strdup(file_location);
	else if (!(ft_strncmp(name, "S", 1)))
		config->spr_texture = ft_strdup(file_location);
	return (0);
}

/* Parses Colors for Floor and Ceiling (F, C), receives item name, color value
in string format Ex. 100,100,0 and Config */
static int	parse_colors(char *name, char *rgb_color, t_config *config)
{
	if (!name || !rgb_color)
		return (1);
	if (!(ft_strncmp(name, "F", 1)))
		config->floor_color = rgb_to_int(rgb_color);
	else if (!(ft_strncmp(name, "C", 1)))
		config->ceiling_color = rgb_to_int(rgb_color);
	return (0);
}

/* Parses Resolution (R) values. Receives two strings and config */
static int	parse_res(char *size_w, char *size_h, t_config *config)
{
	if (!size_w || !size_h)
		error("Missing R value");
	if (ft_strisdigit(size_w) == 0
		|| ft_strisdigit(size_h) == 0)
		error("R values aren't digits");
	config->win_w = ft_atoi(size_w);
	config->win_h = ft_atoi(size_h);
	return (0);
}

/* Receives a string and config and parses it looking for the keywords */
static int	parse_line(char *line, t_config *config)
{
	char	**words_line;

	if (ft_strlen(line) == 0)
		return (0);
	words_line = ft_split(line, ' ');
	if (!(ft_strncmp(words_line[0], "R", 1)))
		parse_res(words_line[1], words_line[2], config);
	else if (!(ft_strncmp(words_line[0], "NO", 2))
		|| !(ft_strncmp(words_line[0], "SO", 2))
		|| !(ft_strncmp(words_line[0], "WE", 2))
		|| !(ft_strncmp(words_line[0], "EA", 2))
		|| !(ft_strncmp(words_line[0], "S", 1)))
		parse_textures(words_line[0], words_line[1], config);
	else if (!(ft_strncmp(words_line[0], "F", 1))
		|| !(ft_strncmp(words_line[0], "C", 1)))
		parse_colors(words_line[0], words_line[1], config);
	else
		parse_map(line, config);
	free_split(words_line);
	return (0);
}

/* Receives a file address and config and parsers its values to config */
int	parse_cub(char const *file, t_config *config)
{
	int		fd;
	char	*line;
	int		gnl_return;

	fd = open(file, O_RDONLY);
	check_file_exists(file);
	while (true)
	{
		gnl_return = get_next_line(fd, &line);
		if (gnl_return == -1)
			return (1);
		parse_line(line, config);
		free(line);
		if (gnl_return == 0)
			break ;
	}
	close(fd);
	return (0);
}
