/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:18:19 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 12:14:54 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_checkcolor(int i, t_env *e)
{
	if (i >= e->itmax)
		return (e->colormap[e->indexcolor][0]);
	if (i < e->itmax && i >= (e->itmax - (e->itmax - 80)))
		return (e->colormap[e->indexcolor][1] + (e->i * 1.2));
	if (i < (e->itmax - (e->itmax - 80)) && i >= (e->itmax - (e->itmax - 60)))
		return (e->colormap[e->indexcolor][2] + (e->i * 1.2));
	if (i < (e->itmax - (e->itmax - 60) && i >= (e->itmax - (e->itmax - 40))))
		return (e->colormap[e->indexcolor][3] + (e->i * 1.2));
	if (i < (e->itmax - (e->itmax - 40)) && i >= (e->itmax - (e->itmax - 20)))
		return (e->colormap[e->indexcolor][4] + (e->i * 1.2));
	if (i < (e->itmax - (e->itmax - 20)) && i >= (e->itmax - (e->itmax - 10)))
		return (e->colormap[e->indexcolor][5] + (e->i * 1.2));
	if (i < (e->itmax - (e->itmax - 10)) && i >= (e->itmax - (e->itmax - 7)))
		return (e->colormap[e->indexcolor][6] + (e->i * 1.2));
	return (e->colormap[e->indexcolor][7] + (e->i * 1.2));
}

t_env				*ft_initmandel(t_env *e)
{
	e->x2 = 0.6;
	e->x1 = -2.1;
	e->y2 = 1.2;
	e->y1 = -1.2;
	if (e->zoomact == 0)
	{
		e->zoom = 300;
		e->itmax = 100;
	}
	e->imagx = (e->x2 - e->x1) * (e->zoom);
	e->imagy = (e->y2 - e->y1) * (e->zoom);
	return (e);
}

void				ft_mandelbrot(t_env *e)
{
	e = ft_initmandel(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->imagx, e->imagy, "fract'ol");
	e->colormap = ft_initcolor(e);
	if (e->buildmap == 0)
		e->map3d = ft_buildmap(e->imagx, e->imagy);
	drawfract(e);
	mlx_hook(e->win, 2, 0, (int (*)())ft_keyhook, e);
	mlx_hook(e->win, 4, 0, ft_mousehook, e);
	mlx_loop(e->mlx);
}

static t_env		*ft_initdraw(t_env *e, int x, int y)
{
	e->cr = x / e->zoom + e->x1;
	e->ci = y / e->zoom + e->y1;
	e->zr = 0;
	e->zi = 0;
	e->i = 0;
	return (e);
}

void				drawmandelbrot(t_env *e)
{
	double tmp;

	e->y = -1;
	while (++e->y < e->imagy)
	{
		e->x = -1;
		while (++e->x < e->imagx)
		{
			e = ft_initdraw(e, e->x, e->y);
			while ((e->zr * e->zr + e->zi * e->zi) < 4 && e->i < e->itmax)
			{
				tmp = e->zr;
				e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
				e->zi = 2 * e->zi * tmp + e->ci;
				e->i++;
			}
			e->color = ft_checkcolor(e->i, e);
			if (e->act3d == 1)
				choosecol(e->i, e, e->x, e->y);
			if (((e->y) < e->imagy) && e->x < e->imagx)
				putcolorpix(e);
		}
	}
}
