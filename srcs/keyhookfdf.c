/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhookfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:34:16 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 16:08:35 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void			posy(t_fdf *f, int keycode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < f->hmap)
	{
		while (j < f->lmap)
		{
			if (keycode == 126)
				f->coory[i][j] -= 20;
			else
				f->coory[i][j] += 20;
			j++;
		}
		j = 0;
		i++;
	}
	f->xstart = f->coorx[0][0];
	f->ystart = f->coory[0][0];
	redraw(f);
}

void			posx(t_fdf *f, int keycode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < f->hmap)
	{
		while (j < f->lmap)
		{
			if (keycode == 124)
				f->coorx[i][j] += 20;
			else
				f->coorx[i][j] -= 20;
			j++;
		}
		j = 0;
		i++;
	}
	f->xstart = f->coorx[0][0];
	f->ystart = f->coory[0][0];
	redraw(f);
}

void			ft_chcolor(t_fdf *f, int keycode)
{
	if (keycode == 0)
		f->color = (int)0x00F34242;
	else if (keycode == 1)
		f->color = (int)0x00FEFEFE;
	else if (keycode == 2)
		f->color = (int)0x0032E844;
	else
	{
		redraw(f);
		f->color += 1000;
		return ;
	}
}

void			ft_zoom(t_fdf *f, int keycode, int flag)
{
	if (flag == 1)
		return ;
	if (keycode == 47 && f->xspace >= 0)
	{
		f->xstart -= 360;
		f->ystart -= 320;
		f->xspace += 2;
		f->yspace += 1;
	}
	else if (f->xspace >= 2 && f->yspace > 1)
	{
		f->xstart += 360;
		f->ystart += 320;
		f->xspace -= 2;
		f->yspace -= 1;
	}
	if (f->xspace > 0)
		fill(f);
	else
		return ;
	redraw(f);
}

void			ft_resetfdf(t_fdf *f)
{
	f->xstart = 440;
	f->ystart = 320;
	f->alt1 = 0;
	f->alt2 = 0;
	f->alt3 = 0;
	f->alt4 = 0;
	f->alt5 = 0;
	f->alt6 = 0;
	f->alt7 = 0;
	f->xspace = 3;
	f->yspace = 1;
	fill(f);
}
