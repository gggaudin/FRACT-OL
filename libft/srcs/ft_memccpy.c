/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:06:35 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/16 17:58:57 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while ((i < n) && (((unsigned char*)src)[i] != (unsigned char)c))
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		((unsigned char*)dest)[i] = (unsigned char)c;
		i++;
		return (&((unsigned char*)dest)[i]);
	}
}
