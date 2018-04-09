/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:45:49 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 16:03:59 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		findfly(int **map, t_env *e, t_fdf *f)
{
	int i;
	int j;

	i = -1;
	while (++i < e->imagy)
	{
		j = 0;
		while (j < e->imagx && map[i][j] == 0)
			j++;
		if (map[i][j] != 0)
		{
			f->fy = i;
			break ;
		}
	}
	findly(map, e, f);
}

void		findly(int **map, t_env *e, t_fdf *f)
{
	int i;
	int j;

	i = e->imagy;
	while (--i >= 0)
	{
		j = e->imagx - 1;
		while (j >= 0 && map[i][j] == 0)
			j--;
		if (map[i][j] != 0)
		{
			f->ly = i;
			break ;
		}
	}
	f->smy = (f->ly - f->fy) + 1;
}

void		findfx(int **map, t_env *e, t_fdf *f)
{
	int i;
	int j;

	j = 0;
	while (j < e->imagx)
	{
		i = 0;
		while ((i < e->imagy) && (map[i][j] == 0))
			i++;
		if (i == e->imagy)
			j++;
		else if (map[i][j] != 0 && i != e->imagy)
		{
			f->fx = j;
			break ;
		}
	}
}

void		findlx(int **map, t_env *e, t_fdf *f)
{
	int i;
	int j;

	j = e->imagx - 1;
	while (j >= 0)
	{
		i = e->imagy - 1;
		while (i >= 0 && map[i][j] == 0)
			i--;
		if (i < 0)
			j--;
		else if (map[i][j] != 0 && i >= 0)
		{
			f->lx = j;
			break ;
		}
	}
	f->smx = (f->lx - f->fx) + 1;
}
