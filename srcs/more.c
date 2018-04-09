/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:44:15 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/09 17:20:21 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void				choosecol(int i, t_env *e, int x, int y)
{
	if (i >= e->itmax)
		e->map3d[y][x] = 70;
	else if (i < e->itmax && i >= (e->itmax - (e->itmax - 80)))
		e->map3d[y][x] = 60;
	else if (i < (e->itmax - (e->itmax - 80)) && i >= (e->itmax - (e->itmax -\
	60)))
		e->map3d[y][x] = 50;
	else if (i < (e->itmax - (e->itmax - 60)) && i >= (e->itmax - (e->itmax -\
	40)))
		e->map3d[y][x] = 40;
	else if (i < (e->itmax - (e->itmax - 40)) && i >= (e->itmax - (e->itmax -\
	20)))
		e->map3d[y][x] = 30;
	else if (i < (e->itmax - (e->itmax - 20)) && i >= (e->itmax - (e->itmax -\
	10)))
		e->map3d[y][x] = 20;
	else if (i < (e->itmax - (e->itmax - 10)) && i >= (e->itmax - (e->itmax -\
	7)))
		e->map3d[y][x] = 10;
}

void				putcolorpix(t_env *e)
{
	int index;

	index = (e->y * e->szline) + (e->x * (e->bpp / 8));
	e->data[index] = (char)e->color;
	e->data[index + 1] = (char)(e->color >> 8);
	e->data[index + 2] = (char)(e->color >> 16);
}

int					**ft_initcolor(t_env *e)
{
	int **tab;
	int i;

	i = 0;
	tab = (int**)ft_memalloc(sizeof(int*) * 5);
	while (i < 5)
	{
		tab[i] = (int*)ft_memalloc(sizeof(int) * 8);
		i++;
	}
	tab = colorbase(tab, e);
	tab = colorpsyche(tab, e);
	tab = colorfract(tab, e);
	tab = colorvoodoo(tab, e);
	tab = colorbatman(tab, e);
	return (tab);
}

void				drawfract(t_env *e)
{
	if (e->act3d == 0)
	{
		e->img = mlx_new_image(e->mlx, e->imagx, e->imagy);
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->szline, &e->endian);
	}
	if (e->map == MANDELBROT)
		drawmandelbrot(e);
	else if (e->map == BATMAN)
		drawbatman(e);
	else if (e->map == CELTIC)
		drawceltic(e);
	else if (e->map == JULIA)
		drawjulia(e);
	if (e->act3d == 0)
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->map == BATMAN)
	{
		mlx_string_put(e->mlx, e->win, 350, 10, 0x00F9FE6B, "FIND BATMAN");
		mlx_string_put(e->mlx, e->win, 340, 40, 0x00F9FE6B, "CLICK AND DIG");
		if (e->pause == 1)
		{
			mlx_string_put(e->mlx, e->win, 100, 600, 0x00F9FE6B, "IT'S BATMAN");
			system("afplay batman.mp3&");
		}
	}
}

int					**ft_buildmap(int x, int y)
{
	int **map;
	int i;

	i = 0;
	map = (int**)ft_memalloc(sizeof(int*) * y);
	while (i < y)
	{
		map[i] = (int*)ft_memalloc(sizeof(int) * x);
		i++;
	}
	return (map);
}
