/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:09:45 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/21 16:00:08 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == *little)
		{
			j = 0;
			while (little[j] && little[j] == big[i + j])
				j++;
			if (little[j] == '\0' && (i + j) <= len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
