/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:40:34 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/16 17:25:31 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(int n)
{
	int i;

	i = 0;
	if ((n < 0) || (n == 0))
		i = 1;
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*new;
	unsigned int	nb;

	nb = n < 0 ? -n : n;
	len = ft_lenstr(n);
	i = len - 1;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i > 0)
	{
		new[i--] = (48 + (nb % 10));
		nb = (nb / 10);
	}
	if (n < 0)
		new[0] = '-';
	else
		new[i] = (48 + nb);
	new[len] = '\0';
	return (new);
}
