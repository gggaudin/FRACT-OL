/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:00:55 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/02/19 13:03:36 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct		s_line
{
	char			*stck;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
