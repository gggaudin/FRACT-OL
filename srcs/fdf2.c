/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:28:02 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/13 12:57:48 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			*stockx(int x, int *tab, t_fdf *f)
{
	int i;

	i = 0;
	while (i < f->lmap)
	{
		tab[i] = x;
		x = x + f->xspace;
		i++;
	}
	return (tab);
}

int			*stocky(int k, int *tab, int z, t_fdf *f)
{
	int j;

	j = 0;
	while (j < f->lmap)
	{
		tab[j] = (z - (f->tabmap[k][j]));
		j++;
	}
	return (tab);
}

void		fill(t_fdf *f)
{
	int i;
	int x;
	int z;

	i = 0;
	f->flagiso = 0;
	x = f->xstart;
	z = f->ystart;
	f->coorx = (int**)ft_memalloc(sizeof(int*) * (f->hmap));
	f->coory = (int**)ft_memalloc(sizeof(int*) * (f->hmap));
	while (i < f->hmap)
	{
		f->coorx[i] = (int*)ft_memalloc(sizeof(int) * (f->lmap));
		f->coory[i] = (int*)ft_memalloc(sizeof(int) * (f->lmap));
		f->coorx[i] = stockx(x, f->coorx[i], f);
		f->coory[i] = stocky(i, f->coory[i], z, f);
		z = z + f->yspace;
		x = x - (f->xspace / 2);
		i++;
	}
}

void		ft_dxdy(t_calc *pts, t_fdf *f)
{
	int cumul;
	int k;

	cumul = pts->dx / 2;
	k = 1;
	while (k <= pts->dx)
	{
		pts->x += pts->xinc;
		cumul += pts->dy;
		if (cumul >= pts->dx)
		{
			cumul -= pts->dx;
			pts->y = pts->y + pts->yinc;
		}
		pixel_put_to_image(f, pts->x, pts->y);
		k++;
	}
}

void		ft_dydx(t_calc *pts, t_fdf *f)
{
	int cumul;
	int k;

	cumul = pts->dy / 2;
	k = 1;
	while (k <= pts->dy)
	{
		pts->y += pts->yinc;
		cumul += pts->dx;
		if (cumul >= pts->dy)
		{
			cumul -= pts->dy;
			pts->x = pts->x + pts->xinc;
		}
		pixel_put_to_image(f, pts->x, pts->y);
		k++;
	}
}
