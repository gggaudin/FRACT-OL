/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 22:12:56 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 12:09:29 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env			*ft_initjulia(t_env *e)
{
	e->x1 = -1;
	e->x2 = 1;
	e->y1 = -1.2;
	e->y2 = 1.2;
	if (e->zoomact == 0)
	{
		e->zoom = 300;
		e->itmax = 100;
	}
	e->pause = -1;
	e->imagx = (e->x2 - e->x1) * e->zoom;
	e->imagy = (e->y2 - e->y1) * e->zoom;
	return (e);
}

void			ft_julia(t_env *e)
{
	e = ft_initjulia(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->imagx, e->imagy, "fract'ol");
	e->colormap = ft_initcolor(e);
	if (e->buildmap == 0)
		e->map3d = ft_buildmap(e->imagx, e->imagy);
	drawfract(e);
	mlx_hook(e->win, 2, 0, (int (*)())ft_keyhook, e);
	mlx_hook(e->win, 4, 0, ft_mousehook, e);
	mlx_hook(e->win, 6, 0, ft_movemouse, e);
	mlx_loop(e->mlx);
}

static	t_env	*ft_initdraw(t_env *e, int x, int y)
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

void			drawjulia(t_env *e)
{
	float tmp;

	e->y = -1;
	while (++e->y < e->imagy)
	{
		e->x = -1;
		while (++e->x < e->imagx)
		{
			e = ft_initdraw(e, e->x, e->y);
			while ((e->zr * e->zr + e->zi * e->zi) < 4 && e->i <= e->itmax)
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
