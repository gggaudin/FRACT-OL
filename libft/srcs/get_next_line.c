/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:25:47 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/02/19 13:06:57 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fillline(t_line *current, char **line)
{
	char		*tmp;

	*line = ft_strjoin_free(*line, current->stck, '\n', 0);
	if (ft_strchr(current->stck, '\n'))
	{
		tmp = ft_strdup(ft_strchr(current->stck, '\n') + 1);
		free(current->stck);
		current->stck = tmp;
	}
	else
		ft_bzero(current->stck, ft_strlen(current->stck) + 1);
}

static int		ft_return(t_line *current, char **line)
{
	char		*buf;
	int			ret;

	buf = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(current->stck, '\n') &&
			(ret = read(current->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			free(buf);
			return (ret);
		}
		buf[ret] = '\0';
		current->stck = ft_strjoin_free(current->stck, buf, '\0', 1);
	}
	free(buf);
	if (!*current->stck)
	{
		free(current->stck);
		*line = ft_strnew(0);
		return (0);
	}
	ft_fillline(current, line);
	return (1);
}

static void		ft_add(t_line **begin, t_line *current)
{
	t_line	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = current;
	}
	else
		*begin = current;
}

static t_line	*ft_new_list(const int fd)
{
	t_line	*new;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	new->stck = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*begin;
	t_line			*current;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!begin)
		begin = ft_new_list(fd);
	current = begin;
	while (current && current->fd != fd)
		current = current->next;
	if (!current)
	{
		current = ft_new_list(fd);
		ft_add(&begin, current);
	}
	*line = "";
	return (ft_return(current, line));
}
