/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:31:07 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/17 11:04:10 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	size_t i;
	size_t j;

	i = 0;
	if (*small == '\0')
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == *small)
		{
			j = 0;
			while ((small[j]) && (small[j] == big[i + j]))
				j++;
			if (small[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
