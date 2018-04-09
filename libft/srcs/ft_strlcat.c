/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:16:34 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/21 09:10:06 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dest_cpy;
	const char		*src_cpy;
	size_t			i;
	size_t			dlen;

	i = size;
	dest_cpy = dest;
	src_cpy = src;
	while (i-- && *dest_cpy)
		dest_cpy++;
	dlen = dest_cpy - dest;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen((char *)src_cpy));
	while (*src_cpy)
	{
		if (i != 1)
		{
			*dest_cpy++ = *src_cpy;
			--i;
		}
		src_cpy++;
	}
	*dest_cpy = '\0';
	return (dlen + (src_cpy - src));
}
