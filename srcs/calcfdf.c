/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcfdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:44:24 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 15:55:53 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		calcptcurr(t_fdf *f, t_calc *pts, int i, int j)
{
	if (f->tabmap[i][j] == 10)
		pts->y = f->coory[i][j] - f->alt1;
	else if (f->tabmap[i][j] == 20)
		pts->y = f->coory[i][j] - f->alt2;
	else if (f->tabmap[i][j] == 30)
		pts->y = f->coory[i][j] - f->alt3;
	else if (f->tabmap[i][j] == 40)
		pts->y = f->coory[i][j] - f->alt4;
	else if (f->tabmap[i][j] == 50)
		pts->y = f->coory[i][j] - f->alt5;
	else if (f->tabmap[i][j] == 60)
		pts->y = f->coory[i][j] - f->alt6;
	else if (f->tabmap[i][j] == 70)
		pts->y = f->coory[i][j] - f->alt7;
}

void		calcptnxtl(t_fdf *f, t_calc *pts, int i, int j)
{
	if (f->tabmap[i + 1][j] == 10)
		pts->dy = (f->coory[i + 1][j] - f->alt1) - pts->y;
	else if (f->tabmap[i + 1][j] == 20)
		pts->dy = (f->coory[i + 1][j] - f->alt2) - pts->y;
	else if (f->tabmap[i + 1][j] == 30)
		pts->dy = (f->coory[i + 1][j] - f->alt3) - pts->y;
	else if (f->tabmap[i + 1][j] == 40)
		pts->dy = (f->coory[i + 1][j] - f->alt4) - pts->y;
	else if (f->tabmap[i + 1][j] == 50)
		pts->dy = (f->coory[i + 1][j] - f->alt5) - pts->y;
	else if (f->tabmap[i + 1][j] == 60)
		pts->dy = (f->coory[i + 1][j] - f->alt6) - pts->y;
	else if (f->tabmap[i + 1][j] == 70)
		pts->dy = (f->coory[i + 1][j] - f->alt7) - pts->y;
}

void		calcptnxtpt(t_fdf *f, t_calc *pts, int i, int j)
{
	if (f->tabmap[i][j + 1] == 10)
		pts->dy = (f->coory[i][j + 1] - f->alt1) - pts->y;
	else if (f->tabmap[i][j + 1] == 20)
		pts->dy = (f->coory[i][j + 1] - f->alt2) - pts->y;
	else if (f->tabmap[i][j + 1] == 30)
		pts->dy = (f->coory[i][j + 1] - f->alt3) - pts->y;
	else if (f->tabmap[i][j + 1] == 40)
		pts->dy = (f->coory[i][j + 1] - f->alt4) - pts->y;
	else if (f->tabmap[i][j + 1] == 50)
		pts->dy = (f->coory[i][j + 1] - f->alt5) - pts->y;
	else if (f->tabmap[i][j + 1] == 60)
		pts->dy = (f->coory[i][j + 1] - f->alt6) - pts->y;
	else if (f->tabmap[i][j + 1] == 70)
		pts->dy = (f->coory[i][j + 1] - f->alt7) - pts->y;
}

void		initcolofdf(t_fdf *f, int i, int j)
{
	if (f->tabmap[i][j] == 70)
		f->color = 0x00878787;
	else if (f->tabmap[i][j] == 60)
		f->color = 0x000C6DE8;
	else if (f->tabmap[i][j] == 50)
		f->color = 0x000D38FF;
	else if (f->tabmap[i][j] == 40)
		f->color = 0x000C6DE8;
	else if (f->tabmap[i][j] == 30)
		f->color = 0x00FE0055;
	else if (f->tabmap[i][j] == 20)
		f->color = 0x000CE1E8;
	else if (f->tabmap[i][j] == 10)
		f->color = 0x000DFFC3;
	else
		f->color = 0x0042F3D8;
}
