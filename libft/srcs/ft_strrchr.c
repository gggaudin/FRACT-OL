/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:51:26 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/17 16:45:04 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	if ((unsigned char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (&((char*)s)[i]);
	}
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			count++;
			j = i;
		}
		i++;
	}
	if (count > 0)
		return (&((char*)s)[j]);
	return (0);
}
