/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:42:09 by ggaudin-          #+#    #+#             */
/*   Updated: 2016/11/17 19:11:31 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, size_t start, size_t n)
{
	char	*ret;

	if (!s)
		return (0);
	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(ret, &s[start], n);
	ret[n] = '\0';
	return (ret);
}
