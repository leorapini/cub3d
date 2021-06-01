/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:14:31 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/01 19:08:46 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_split(char **words_line)
{
	int	i;

	i = 0;
	while (words_line[i] != NULL)
	{
		free(words_line[i]);
		i++;
	}
	free(words_line);
}

static char	*join_hex(char *hex_dest, char *hex)
{
	char	*temp;

	temp = ft_strjoin(hex_dest, hex);
	free(hex_dest);
	hex_dest = temp;
	return (hex_dest);
}

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
