/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:26:22 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/09 17:08:28 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						ft_movemouse(int x, int y, t_env *e)
{
	if (e->pause == -1)
	{
		e->cr = ((float)(x - 450) / 450);
		e->ci = ((float)(y - 450) / 450);
		e->mousemoved = 1;
		mlx_clear_window(e->mlx, e->win);
		if (e->map == BATMAN)
		{
			if (x == 450 && y == 707)
			{
				e->indexcolor = 4;
				e->pause = 1;
			}
			else
				e->indexcolor = 0;
		}
		drawfract(e);
	}
	return (0);
}

static void				ft_reset(t_env *e)
{
	e->zoomact = 0;
	if (e->map == MANDELBROT)
		e = ft_initmandel(e);
	else if (e->map == JULIA)
		e = ft_initjulia(e);
	else
		e = ft_initceltic(e);
	drawfract(e);
}

static void				restart(t_env *e)
{
	if (e->map == MANDELBROT || e->map == CELTIC)
	{
		if (e->zoomact == 0)
			e = ft_initmandel(e);
	}
	drawfract(e);
}

int						ft_mousehook(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 && e->map != BATMAN && e->zoom >= 300)
		zoomin(e, x, y);
	if (keycode == 4 && e->map != BATMAN && e->zoom >= 360)
		zoomout(e, x, y);
	if (keycode == 1 && e->map == BATMAN)
		flagbat(x, y, e);
	if (e->zoom >= 299 && e->zoom < 360)
	{
		e->itmax = 100;
		e->zoomact = 0;
	}
	else
		e->zoomact = 1;
	if (e->buildmap == 0)
		e->buildmap = 1;
	if (e->map == BATMAN && e->pause == -1)
	{
		locbat(e, x, y);
		return (0);
	}
	restart(e);
	return (0);
}

int						ft_keyhook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 82 || keycode == 83 || keycode == 84 || keycode == 85)
		chcolfract(keycode, e);
	if (keycode == 49 && (e->map == JULIA))
		e->pause *= -1;
	if (keycode == 15)
	{
		ft_reset(e);
		return (0);
	}
	if (keycode == 3 && e->map != BATMAN)
	{
		e->act3d = 1;
		restart(e);
		e->act3d = 0;
		ft_fdf(e->map3d, e);
		return (0);
	}
	if (e->buildmap == 0)
		e->buildmap = 1;
	mlx_clear_window(e->mlx, e->win);
	restart(e);
	return (0);
}
