/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:12:45 by lpinheir          #+#    #+#             */
/*   Updated: 2021/02/20 13:55:37 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	int		len;

	target = (char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*s == target && target == '\0')
			return ((char *)s);
		if (*s == target)
			return ((char *)s);
		if (*s == '\0')
			return (0);
		s++;
	}
	return (0);
}
