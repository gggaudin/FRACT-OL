/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:00:13 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/11 10:06:26 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	i;
	size_t	j;

	if ((s1) && (s2))
	{
		len1 = ft_strlen(s1);
		if ((len1 != ft_strlen(s2)) || (!s1) || (!s2))
			return (0);
		i = 0;
		j = 0;
		while (i < len1)
		{
			if (s1[i] == s2[i])
				j++;
			i++;
		}
		if (j == len1)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
