/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:24:16 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 12:04:45 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env				*ft_initbatman(t_env *e)
{
	e->itmax = 100;
	e->x1 = -1.35;
	e->x2 = 0.65;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 300;
	e->pause = -1;
	e->imagx = (e->x2 - e->x1) * (e->zoom * 1.5);
	e->imagy = (e->y2 - e->y1) * (e->zoom * 1.5);
	return (e);
}

void				ft_batman(t_env *e)
{
	e = ft_initbatman(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, XWIN, YWIN, "fract'ol");
	e->colormap = ft_initcolor(e);
	drawfract(e);
	mlx_hook(e->win, 2, 0, (int (*)())ft_keyhook, e);
	mlx_hook(e->win, 4, 0, ft_mousehook, e);
	mlx_hook(e->win, 6, 0, ft_movemouse, e);
	mlx_loop(e->mlx);
}

static	t_env		*ft_initdraw(t_env *e, int x, int y)
{
	if (e->mousemoved == 0)
	{
		e->cr = 0.285;
		e->ci = 0.01;
	}
	e->zr = x / e->zoom + e->x1;
	e->zi = y / e->zoom + e->y1;
	e->i = 0;
	return (e);
}

void				drawbatman(t_env *e)
{
	double	tmp;

	e->y = -1;
	while (++e->y < e->imagy)
	{
		e->x = -1;
		while (++e->x < e->imagx)
		{
			e = ft_initdraw(e, e->x, e->y);
			while (e->i < e->itmax && (e->zr * e->zr + e->zi * e->zi) < 4)
			{
				tmp = e->zr;
				e->zr = e->zr * e->zr * e->zr -
					(3 * e->zr * e->zi * e->zi) + e->cr;
				e->zi = (3 * tmp * tmp * e->zi) + e->ci;
				e->i++;
			}
			e->color = ft_checkcolor(e->i, e);
			if (((e->y) < YWIN) && e->x < XWIN)
				putcolorpix(e);
		}
	}
}
