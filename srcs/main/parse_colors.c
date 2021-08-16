/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:51:47 by lpinheir          #+#    #+#             */
/*   Updated: 2021/08/16 18:51:58 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives line and returns rgb value as string without letter and spaces */
static char	*delete_space(char *line)
{
	char	*rgb;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (line[i++])
	{
		if (line[i] == ',' || ft_isdigit(line[i]))
			len++;
	}
	rgb = (char *) malloc(sizeof(char *) * (len + 1));
	i = 0;
	j = 0;
	while (line[i++])
	{
		if (line[i] == ',' || ft_isdigit(line[i]))
		{
			rgb[j] = line[i];
			j++;
		}
	}
	rgb[j] = '\0';
	return (rgb);
}

/* Receives address of ceiling or floor color (int) and sets its based
on string version of it */
static void	line_rgb_to_int(int *config_color, char *line)
{
	char	*rgb;

	rgb = delete_space(line);
	*config_color = rgb_to_int(rgb);
	free(rgb);
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
