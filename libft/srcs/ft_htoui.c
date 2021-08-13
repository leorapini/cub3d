/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:01:49 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/01 16:00:53 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_htoui(char *h)
{
	uint32_t	result;

	result = 0;
	while (*h)
	{
		if (*h >= '0' && *h <= '9')
			result = (result * 16) + (*h - '0');
		else if (*h >= 'a' && *h <= 'f')
			result = (result * 16) + ((*h - 'a') + 10);
		else if (*h >= 'A' && *h <= 'F')
			result = (result * 16) + ((*h - 'A') + 10);
		h++;
	}
	return (result);
}
