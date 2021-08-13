/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:48:38 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/24 08:42:07 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newdst;
	unsigned char	*newsrc;

	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		newdst = newdst + (len - 1);
		newsrc = newsrc + (len - 1);
		while (len > 0)
		{
			*newdst-- = *newsrc--;
			len--;
		}
	}
	return (dst);
}
