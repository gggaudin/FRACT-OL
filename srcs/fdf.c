/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:14:27 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/09 17:08:00 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			pixel_put_to_image(t_fdf *f, int x, int y)
{
	int coor;

	coor = (y * 2500) + x;
	if (((x < 2500 && x > 0) && (y < 1300 && y > 0)) && (coor < (2500 * 1300)) \
			&& (coor > 0))
		f->data[coor] = f->color;
}

void			draw(t_fdf *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	f->img = mlx_new_image(f->mlx, 2500, 1300);
	f->data = (int *)mlx_get_data_addr(f->img, &f->bpp, &f->szline,
			&f->endian);
	while (i < f->hmap)
	{
		while (j < (f->lmap))
		{
			initcolofdf(f, i, j);
			xegment(f, i, j);
			yegment(f, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	ft_info(f);
}

void			ft_info(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 15, 1, 0x00F9FE6B, f->baninfo);
	mlx_string_put(f->mlx, f->win, 15, 10, 0x00F9FE6B, f->info);
	mlx_string_put(f->mlx, f->win, 15, 18, 0x00F9FE6B, f->baninfo);
}

static int		**ft_createmap3d(int **map, t_fdf *f, t_env *e)
{
	int **new;
	int i;
	int j;
	int n;
	int m;

	findfly(map, e, f);
	findfx(map, e, f);
	findlx(map, e, f);
	new = (int **)ft_memalloc(sizeof(int*) * f->smy);
	i = -1;
	n = 0;
	while (++i < f->smy)
	{
		new[i] = (int*)ft_memalloc(sizeof(int) * f->smx);
		j = -1;
		m = 0;
		while (++j < f->smx)
		{
			new[i][j] = map[f->fy + n][f->fx + m];
			m++;
		}
		n++;
	}
	return (new);
}

void			ft_fdf(int **map, t_env *e)
{
	t_fdf	*f;

	f = ft_memalloc(sizeof(t_fdf));
	f->xstart = 440;
	f->ystart = 320;
	f->xspace = 3;
	f->yspace = 1;
	f->info = "Type 1 to get INFO";
	f->baninfo = " ";
	f->flag = 0;
	f->color = (int)0x0042F3DB;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 2500, 1300, "fdf");
	f->tabmap = ft_createmap3d(map, f, e);
	f->hmap = f->smy;
	f->lmap = f->smx;
	fill(f);
	draw(f);
	mlx_hook(f->win, 2, 2, (int (*)())key_hook, f);
	mlx_loop(f->mlx);
}
