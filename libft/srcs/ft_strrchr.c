/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:08:34 by lpinheir          #+#    #+#             */
/*   Updated: 2021/02/20 13:48:39 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		target;
	const char	*found;
	int			len;

	target = (unsigned char)c;
	found = 0;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*s == target)
			found = s;
		if (*s == 0)
			break ;
		len--;
		s++;
	}
	return ((char *)found);
}
