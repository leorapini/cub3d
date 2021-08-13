/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:48:50 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:09:49 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_startindex(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_endindex(const char *s1, const char *set)
{
	size_t	i;

	if (ft_strlen(s1) == 0)
		return (0);
	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;
	char	*buffer;

	if (!s1)
		return (NULL);
	start_i = ft_startindex(s1, set);
	end_i = ft_endindex(s1, set);
	if (start_i > end_i)
		return (ft_strdup(""));
	buffer = (char *)malloc(sizeof(char) * (end_i - start_i + 2));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1 + start_i, end_i - start_i + 2);
	return (buffer);
}
