/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:35:31 by lpinheir          #+#    #+#             */
/*   Updated: 2021/02/20 13:58:10 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	buffer = malloc(sizeof(*buffer) * len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
