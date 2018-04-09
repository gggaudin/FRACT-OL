/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhookfdf2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:32:53 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/15 14:25:13 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int				redraw(t_fdf *f)
{
	mlx_destroy_image(f->mlx, f->img);
	draw(f);
	return (0);
}

void			ft_dispinfo(t_fdf *f, int keycode)
{
	if (keycode == 18)
	{
		f->baninfo = "---------------------------------------------------------\
	---------------------------------------------------";
		f->info = "ZOOM: < or > // \
	POSITION: use Arrows // HEIGHT: Q W E R T Y U I O P { } K L // RESET: enter\
	// REDUCE INFO:2";
	}
	else
	{
		f->baninfo = " ";
		f->info = "Type 1 to get INFO";
	}
}

void			ft_alt2(t_fdf *f, int keycode)
{
	if (keycode == 31)
		f->alt5 -= 5;
	if (keycode == 35)
		f->alt5 += 5;
	if (keycode == 33)
		f->alt6 -= 5;
	if (keycode == 30)
		f->alt6 += 5;
	if (keycode == 40)
		f->alt7 -= 5;
	if (keycode == 37)
		f->alt7 += 5;
}

void			ft_alt(t_fdf *f, int keycode)
{
	if (keycode == 13)
		f->alt1 += 5;
	if (keycode == 12)
		f->alt1 -= 5;
	if (keycode == 14)
		f->alt2 -= 5;
	if (keycode == 15)
		f->alt2 += 5;
	if (keycode == 17)
		f->alt3 -= 5;
	if (keycode == 16)
		f->alt3 += 5;
	if (keycode == 32)
		f->alt4 -= 5;
	if (keycode == 34)
		f->alt4 += 5;
	else
		ft_alt2(f, keycode);
}

int				key_hook(int keycode, t_fdf *f)
{
	if (keycode == 18 || keycode == 19)
		ft_dispinfo(f, keycode);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 3)
		ft_chcolor(f, keycode);
	if (keycode == 47 || keycode == 43)
		ft_zoom(f, keycode, f->flagiso);
	if (keycode == 76)
		ft_resetfdf(f);
	if (keycode == 53)
		exit(0);
	if (keycode == 12 || keycode == 13 || keycode == 14 || keycode == 15 ||\
			keycode == 16 || keycode == 17 || keycode == 32 || keycode == 34
			|| keycode == 31 || keycode == 35 || keycode == 33 || keycode == 30\
			|| keycode == 40 || keycode == 37)
		ft_alt(f, keycode);
	if (keycode == 126 || keycode == 125)
		posy(f, keycode);
	if (keycode == 124 || keycode == 123)
		posx(f, keycode);
	if (keycode == 35)
		fill(f);
	redraw(f);
	return (0);
}
