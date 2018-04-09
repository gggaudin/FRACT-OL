/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:36 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/18 15:02:51 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int neg;

	i = 0;
	result = 0;
	neg = 1;
	if (str[i])
	{
		while (str[i] == 32 || str[i] >= 127 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				neg = -neg;
			i++;
		}
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			result = ((result * 10) + (str[i] - 48));
			i++;
		}
		return (result * neg);
	}
	return (0);
}
