/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:21:03 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/17 15:26:32 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (src > dest)
	{
		while (len > 0)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
			len--;
		}
	}
	else
	{
		i = len - 1;
		while (len > 0)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i--;
			len--;
		}
	}
	return (dest);
}
