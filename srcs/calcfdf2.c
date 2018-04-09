/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcfdf2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:37:38 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 15:55:08 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	yegment(t_fdf *f, int i, int j)
{
	t_calc pts;

	if (f->tabmap[i][j] > 0)
	{
		if (i == (f->hmap - 1))
			return ;
		ft_initcalcy(&pts, f, i, j);
		pixel_put_to_image(f, pts.x, pts.y);
		if (pts.dx > pts.dy)
			ft_dxdy(&pts, f);
		else
			ft_dydx(&pts, f);
	}
}

void	ft_initcalcy(t_calc *pts, t_fdf *f, int i, int j)
{
	pts->x = f->coorx[i][j];
	if (f->tabmap[i][j] != 0)
		calcptcurr(f, pts, i, j);
	else
		pts->y = f->coory[i][j];
	pts->dx = f->coorx[i + 1][j] - pts->x;
	if (f->tabmap[i + 1][j] != 0)
		calcptnxtl(f, pts, i, j);
	else
		pts->dy = f->coory[i + 1][j] - pts->y;
	pts->xinc = (pts->dx > 0) ? 1 : -1;
	pts->yinc = (pts->dy > 0) ? 1 : -1;
	pts->dx = abs(pts->dx);
	pts->dy = abs(pts->dy);
}

void	ft_initcalcx(t_calc *pts, t_fdf *f, int i, int j)
{
	pts->x = f->coorx[i][j];
	if (f->tabmap[i][j] != 0)
		calcptcurr(f, pts, i, j);
	else
		pts->y = f->coory[i][j];
	pts->dx = f->coorx[i][j + 1] - pts->x;
	if (f->tabmap[i][j + 1] != 0)
		calcptnxtpt(f, pts, i, j);
	else
		pts->dy = (f->coory[i][j + 1]) - pts->y;
	pts->xinc = (pts->dx > 0) ? 1 : -1;
	pts->yinc = (pts->dy > 0) ? 1 : -1;
	pts->dx = abs(pts->dx);
	pts->dy = abs(pts->dy);
}

void	xegment(t_fdf *f, int i, int j)
{
	t_calc pts;

	ft_initcalcx(&pts, f, i, j);
	if (f->tabmap[i][j] > 0)
	{
		if (j == (f->lmap - 1))
		{
			pixel_put_to_image(f, pts.x, pts.y);
			return ;
		}
		pixel_put_to_image(f, pts.x, pts.y);
		if (pts.dx > pts.dy)
			ft_dxdy(&pts, f);
		else
			ft_dydx(&pts, f);
	}
}
