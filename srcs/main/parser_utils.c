/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:14:31 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/03 10:23:15 by lpinheir         ###   ########.fr       */
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

/* Auxiliary function to rgb_to_int. Receives two strings, joins them
and returns the joined string. */
static char	*join_hex(char *hex_dest, char *hex)
{
	char	*temp;

	temp = ft_strjoin(hex_dest, hex);
	free(hex_dest);
	hex_dest = temp;
	return (hex_dest);
}

/* Receives a rgb string in the format Ex. 100,100,0 and returns the int
value referent to that rgb value */
int	rgb_to_int(char	*rgb_color)
{
	char	**numbers;
	char	*hex;
	char	*total_hex;
	int		results;
	int		i;

	i = 0;
	numbers = ft_split(rgb_color, ',');
	total_hex = ft_strdup("");
	while (numbers[i] != NULL)
	{
		if (!(ft_strncmp(numbers[i], "0", 1)))
			hex = ft_strdup("00");
		else
			hex = ft_uitoh(ft_atoi(numbers[i]), 0);
		total_hex = join_hex(total_hex, hex);
		free(hex);
		i++;
	}
	results = ft_htoui(total_hex);
	free(total_hex);
	free_split(numbers);
	return (results);
}

int	check_file_exists(char const *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		printf("Problem with file %s\n", file);
		error("File Doesn't Exist");
	}
	close(fd);
	return (0);
}
