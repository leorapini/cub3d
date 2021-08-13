/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:40:10 by lpinheir          #+#    #+#             */
/*   Updated: 2021/02/20 14:02:26 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	int		len;

	len = ft_strlen(s1);
	buffer = (char *)malloc(sizeof(*s1) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, s1, len + 1);
	return (buffer);
}
