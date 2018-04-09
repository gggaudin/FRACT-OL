/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:26:34 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/17 18:44:59 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if ((s1) && (s2))
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) +
					ft_strlen((char*)s2) + 1));
		if (!new)
			return (NULL);
		while (s1[j])
			new[i++] = s1[j++];
		j = 0;
		while (s2[j])
			new[i++] = s2[j++];
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
