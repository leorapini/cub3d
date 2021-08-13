/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:49:05 by lpinheir          #+#    #+#             */
/*   Updated: 2021/02/08 16:56:06 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	target;
	unsigned char	*newdst;
	unsigned char	*newsrc;

	target = (unsigned char)c;
	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	while (n > 0)
	{
		*newdst = *newsrc;
		if (*newsrc == target)
		{
			newdst++;
			return ((void *)newdst);
		}
		newdst++;
		newsrc++;
		n--;
	}
	return (0);
}
