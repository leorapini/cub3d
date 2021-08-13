/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count_limit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:03:42 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:39:47 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_count_limit(char *s, int limit)
{
	int	counter;

	counter = 0;
	if (s)
	{
		if (limit > 0)
		{
			while (*s != 0 && limit > 0)
			{
				counter += ft_putchar_count(*s);
				s++;
				limit--;
			}
		}
		else
		{
			while (*s != 0)
			{
				counter += ft_putchar_count(*s);
				s++;
			}
		}
	}
	return (counter);
}
