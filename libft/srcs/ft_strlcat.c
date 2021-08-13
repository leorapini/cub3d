/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:01:46 by lpinheir          #+#    #+#             */
/*   Updated: 2021/02/12 18:33:43 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	counter;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	counter = 0;
	while (*dst != 0 && dstsize > 0)
	{
		dst++;
		dstsize--;
		counter++;
	}
	while (*src != 0 && dstsize > 1)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst++ = 0;
	return (srclen + counter);
}
