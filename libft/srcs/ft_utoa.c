/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:17:56 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:31:00 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen_utoa(unsigned int num)
{
	size_t	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

char	*ft_utoa(unsigned int n)
{
	char			*buffer;
	size_t			len;
	unsigned int	new_n;

	new_n = n;
	len = ft_getlen_utoa(n);
	buffer = (char *)malloc(sizeof(char) * len + 1);
	if (!(buffer))
		return (NULL);
	if (new_n == 0)
		buffer[0] = '0';
	buffer[len] = '\0';
	while (new_n != 0 && len >= 0)
	{
		buffer[len - 1] = new_n % 10 + '0';
		new_n = new_n / 10;
		len--;
	}
	return (buffer);
}
