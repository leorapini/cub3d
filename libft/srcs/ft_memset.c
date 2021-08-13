/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:46:08 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:09:22 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*newb;

	newb = (unsigned char *)b;
	while (len > 0)
	{
		*newb = (unsigned char)c;
		newb++;
		len--;
	}
	return (b);
}
