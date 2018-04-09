/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:26:34 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/02/16 17:59:01 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, char c, int atfree)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlenchr(s2, c);
	if (!(new = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != c)
		new[j++] = s2[i++];
	new[j] = '\0';
	if (atfree == 1 || atfree == 3)
		ft_strdel(&s1);
	if (atfree == 2 || atfree == 3)
		ft_strdel(&s2);
	return (new);
}
