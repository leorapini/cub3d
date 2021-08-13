/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:38:43 by lpinheir          #+#    #+#             */
/*   Updated: 2021/05/18 15:01:41 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != 0 && len >= n_len)
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
