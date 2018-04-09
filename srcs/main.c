/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:47:14 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 12:10:04 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_calzoom(t_env *e)
{
	float	zoom;

	zoom = 0.0;
	while (((e->x2 - e->x1) * zoom) < XWIN && ((e->y2 - e->y1) * zoom) < YWIN)
		zoom++;
	zoom -= 1;
	return (zoom);
}

int		run_fract(char *av)
{
	t_env	*e;

	e = ft_memalloc(sizeof(t_env));
	if ((e->map = ft_checkmap(av)) == 0)
		ft_error(WMAP);
	if (e->map == MANDELBROT)
		ft_mandelbrot(e);
	else if (e->map == JULIA)
		ft_julia(e);
	else if (e->map == BATMAN)
		ft_batman(e);
	else if (e->map == CELTIC)
		ft_celtic(e);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_error(PARAM);
	else
		run_fract(av[1]);
	return (0);
}
