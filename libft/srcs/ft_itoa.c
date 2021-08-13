/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:11:20 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:14:30 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(long int num, int sign)
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
	if (sign < 0)
		length++;
	return (length);
}

char	*ft_itoa(int n)
{
	char			*buffer;
	size_t			len;
	int				sign;
	unsigned int	new_n;

	sign = 1;
	if (n < 0)
		sign = -1;
	new_n = (unsigned int)n * sign;
	len = ft_getlen(n, sign);
	buffer = (char *)malloc(sizeof(char) * len + 1);
	if (!buffer)
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
	if (sign == -1)
		buffer[0] = '-';
	return (buffer);
}
