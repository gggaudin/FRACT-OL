/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:06:43 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/14 08:43:45 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	j = 0;
	if ((unsigned char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (&((char*)s)[i]);
	}
	while (s[i])
	{
		if ((s[i] == (unsigned char)c) && (count == 0))
			j = i;
		if (s[i] == (unsigned char)c)
			count++;
		i++;
	}
	if (count > 0)
		return (&((char*)s)[j]);
	return (0);
}
