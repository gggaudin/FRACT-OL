/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:39:34 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 12:05:19 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env			*ft_initceltic(t_env *e)
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

void			ft_celtic(t_env *e)
{
	e = ft_initceltic(e);
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

static t_env	*ft_initdraw(t_env *e, int x, int y)
{
	e->cr = x / e->zoom + e->x1;
	e->ci = y / e->zoom + e->y1;
	e->zr = 0;
	e->zi = 0;
	e->i = 0;
	return (e);
}

void			drawceltic(t_env *e)
{
	double	tmp;

	e->y = -1;
	while (++e->y < e->imagy)
	{
		e->x = -1;
		while (++e->x < e->imagx)
		{
			e = ft_initdraw(e, e->x, e->y);
			while ((((e->zr * e->zr) + (e->zi * e->zi)) < 4)
					&& e->i < (e->itmax))
			{
				tmp = e->zr * e->zi;
				e->zr = fabs((e->zr * e->zr) - (e->zi * e->zi)) + e->cr;
				e->zi = tmp + tmp + e->ci;
				e->i++;
			}
			e->color = ft_checkcolor(e->i, e);
			if (e->act3d == 1)
				choosecol(e->i, e, e->x, e->y);
			if (((e->y < e->imagy && e->x < e->imagx)))
				putcolorpix(e);
		}
	}
}
