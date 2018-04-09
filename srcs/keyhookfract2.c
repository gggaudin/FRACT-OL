/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhookfract2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 12:30:35 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/15 15:03:33 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void			zoomin(t_env *e, int x, int y)
{
	double tmpzoom;

	tmpzoom = e->zoom;
	e->zoom = e->zoom * 1.4;
	e->itmax *= 1.05;
	e->x1 += ((x / tmpzoom) - (x / e->zoom));
	e->y1 += ((y / tmpzoom) - (y / e->zoom));
	mlx_destroy_image(e->mlx, e->img);
}

void			zoomout(t_env *e, int x, int y)
{
	double tmpzoom;

	tmpzoom = e->zoom;
	e->zoom = e->zoom / 1.4;
	e->itmax /= 1.05;
	e->x1 += ((x / tmpzoom) - (x / e->zoom));
	e->y1 += ((y / tmpzoom) - (y / e->zoom));
	mlx_destroy_image(e->mlx, e->img);
}

void			flagbat(int x, int y, t_env *e)
{
	if ((x < 100 || x > 700) || (y < 300 || y > 760))
		e->flagstr = 3;
	else if ((x < 240 || x > 660) || (y < 505 || y > 757))
		e->flagstr = 2;
	else if ((x < 440 || x > 460) || (y < 705 || y > 707))
		e->flagstr = 1;
	else
		e->flagstr = 0;
}

void			locbat(t_env *e, int x, int y)
{
	char	*str;

	str = ft_itoa(sqrt((((450 - x) * (450 - x)) + ((707 - y) * (707 - y)))));
	if (e->pause == -1)
	{
		drawbatman(e);
		if (e->flagstr == 1)
			mlx_string_put(e->mlx, e->win, (x - 50), (y - 20), 0x00F9FE6B,\
	"NEAR");
		else if (e->flagstr == 2)
			mlx_string_put(e->mlx, e->win, (x - 50), (y - 20), 0x00F9FE6B,\
	"NOPE");
		else if (e->flagstr == 3)
			mlx_string_put(e->mlx, e->win, (x - 50), (y - 20), 0x00F9FE6B,\
	"SO FAR");
		mlx_string_put(e->mlx, e->win, (x - 50), (y - 7), 0x00F9FE6B,\
	str);
		ft_strdel(&str);
	}
}

void			chcolfract(int keycode, t_env *e)
{
	if (keycode == 82)
		e->indexcolor = 0;
	else if (keycode == 83)
		e->indexcolor = 1;
	else if (keycode == 84)
		e->indexcolor = 2;
	else
		e->indexcolor = 3;
}
