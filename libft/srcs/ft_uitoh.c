/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:20:53 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:23:54 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen_uitoh(uintptr_t num, int sign)
{
	size_t	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 16;
		length++;
	}
	if (sign < 0)
		length++;
	return (length);
}

char	*ft_uitoh(uintptr_t n, int cap)
{
	char		*buffer;
	int			len;
	uintptr_t	new_n;

	len = ft_getlen_uitoh(n, 1);
	buffer = (char *)malloc(sizeof(char) * len + 1);
	if (!(buffer))
		return (NULL);
	if (n == 0)
		buffer[0] = '0';
	buffer[len] = '\0';
	while (n != 0 && len >= 0)
	{
		new_n = n % 16;
		if (new_n < 10)
			buffer[len - 1] = new_n + 48;
		else if (new_n >= 10 && cap == 0)
			buffer[len - 1] = new_n + 87;
		else
			buffer[len - 1] = new_n + 55;
		n = n / 16;
		len--;
	}
	return (buffer);
}
