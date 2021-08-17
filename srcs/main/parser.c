/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:34:04 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/06 14:39:23 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives name (NO, SO, EA, WE) and checks if value has already been set */
static void	check_duplicate_textures(char *name, t_config config)
{
	if (!(ft_strncmp(name, "NO", 2)))
	{
		if (config.no_texture != NULL)
			error("Error in texture");
	}
	else if (!(ft_strncmp(name, "SO", 2)))
	{
		if (config.so_texture != NULL)
			error("Error in texture");
	}
	else if (!(ft_strncmp(name, "WE", 2)))
	{
		if (config.we_texture != NULL)
			error("Error in texture");
	}
	else if (!(ft_strncmp(name, "EA", 2)))
	{
		if (config.ea_texture != NULL)
			error("Error in texture");
	}
}

/* Parses Textures for SO, SO, WE, EA, S. Receives string with file location
and config and set those locations to each respective item in config */
static void	parse_textures(char *name, char *file_location, t_config *config)
{
	check_file_exists(file_location);
	check_duplicate_textures(name, *config);
	if (!(ft_strncmp(name, "NO", 2)))
	{
		if (config->no_texture == NULL)
			config->no_texture = ft_strdup(file_location);
	}
	else if (!(ft_strncmp(name, "SO", 2)))
	{
		if (config->so_texture == NULL)
			config->so_texture = ft_strdup(file_location);
	}
	else if (!(ft_strncmp(name, "WE", 2)))
	{
		if (config->we_texture == NULL)
			config->we_texture = ft_strdup(file_location);
	}
	else if (!(ft_strncmp(name, "EA", 2)))
	{
		if (config->ea_texture == NULL)
			config->ea_texture = ft_strdup(file_location);
	}
}

/* Parses Colors for Floor and Ceiling (F, C), receives item name, color value
in string format Ex. 100,100,0 and Config */
void	parse_colors(char **words, char *line, int word_count,
	t_config *config)
{
	if (!(ft_strncmp(words[0], "F", 1)))
	{
		if (config->floor_color == -1 && word_count == 2)
			config->floor_color = rgb_to_int(words[1]);
		else if (config->floor_color == -1 && word_count > 2)
			line_rgb_to_int(&config->floor_color, line);
		else
			error("Error in color");
	}
	else if (!(ft_strncmp(words[0], "C", 1)))
	{
		if (config->ceiling_color == -1 && word_count == 2)
			config->ceiling_color = rgb_to_int(words[1]);
		else if (config->ceiling_color == -1 && word_count > 2)
			line_rgb_to_int(&config->ceiling_color, line);
		else
			error("Error in color");
	}
}

/* Receives a string and config and parses it looking for the keywords */
static int	parse_line(char *line, t_config *config)
{
	char	**words_line;
	int		word_count;

	if (ft_strlen(line) == 0 && config->map[0][0] == 0)
		return (0);
	else if (ft_strlen(line) == 0 && config->map[0][0] != 0)
		error(".cub Blank line after map");
	words_line = ft_split(line, ' ');
	word_count = words_counter(words_line);
	if ((!(ft_strncmp(words_line[0], "NO", 2))
			|| !(ft_strncmp(words_line[0], "SO", 2))
			|| !(ft_strncmp(words_line[0], "WE", 2))
			|| !(ft_strncmp(words_line[0], "EA", 2)))
		&& word_count == 2)
		parse_textures(words_line[0], words_line[1], config);
	else if (!(ft_strncmp(words_line[0], "F", 1))
		|| !(ft_strncmp(words_line[0], "C", 1)))
		parse_colors(words_line, line, word_count, config);
	else
	{
		check_config(*config);
		parse_map(line, config);
	}
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
