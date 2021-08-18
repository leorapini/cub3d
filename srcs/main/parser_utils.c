/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:14:31 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/04 16:25:18 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Frees each memory slot allocated by the ft_split function */
void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* Receives array of words and counts how many words are there */
int	words_counter(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		i++;
	return (i);
}

/* Receives a file location and checks if file exists  */
int	check_file_exists(char const *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		error("File Not Found");
	close(fd);
	return (0);
}

int	check_empty_line(char *line, t_config *config)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len == 0 && config->map[0][0] == 0)
		return (1);
	else if ((line_len == 0 && config->map[0][0] != 0)
			&& config->map_ended == 0)
	{
		config->map_ended = 1;
		return (1);
	}
	else if (config->map_ended == 1)
		return (1);
	else
		return (0);
}
