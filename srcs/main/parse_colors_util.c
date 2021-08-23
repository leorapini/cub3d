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

/* Receives s (line) and checks for usual characters and or spaces
between actual numbers Ex. 25 5. This is called when C or F settings
have spaces between commas. Ex. 255,   255 , 255 */
static void	check_number(char *s)
{
	int	i;
	int	number;
	int	lock_number;

	i = 0;
	number = 0;
	lock_number = 0;
	while (s[i++])
	{
		if (s[i] != ',' && s[i] != ' ' && !(ft_isdigit(s[i])) && s[i] != 0)
			error("Error in C or F");
		if (ft_isdigit(s[i]) && lock_number == 0)
			number = 1;
		if (ft_isdigit(s[i]) && lock_number == 1)
			error(".cub C or F settings fail");
		else if (s[i] == ' ' && number == 1)
			lock_number = 1;
		else if (s[i] == ',')
		{
			number = 0;
			lock_number = 0;
		}
	}
}

/* Receives address of ceiling or floor color (int) and sets its based
on string version of it */
void	line_rgb_to_int(int *config_color, char *line)
{
	char	*rgb;

	rgb = delete_space(line);
	*config_color = rgb_to_int(rgb);
	free(rgb);
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

/* Auxiliary function to rgb_to_int. Receives string and checks if value
is a number. Exits with error if that's not the case. Returns hex value
as a string */
static char	*check_hex(char *number)
{
	char	*hex;
	int		int_num;

	int_num = 0;
	if (!(ft_strisdigit(number)))
		error("F or C values aren't numbers");
	if (!(ft_strncmp(number, "0", 1)))
		hex = ft_strdup("00");
	else
	{
		int_num = ft_atoi(number);
		if (int_num > 255)
			error("F or C values are bigger than 255");
		hex = ft_uitoh(int_num, 0);
	}
	return (hex);
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
		hex = check_hex(numbers[i]);
		total_hex = join_hex(total_hex, hex);
		free(hex);
		i++;
	}
	if (i != 3)
		error("Bad F or C color value");
	results = ft_htoui(total_hex);
	free(total_hex);
	free_split(numbers);
	return (results);
}
