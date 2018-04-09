/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:04:49 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/15 15:10:54 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int code)
{
	if (code == PARAM)
	{
		ft_putendl("usage: ./fractol [ma] --> MANDELBROT FRACTAL");
		ft_putendl("       ./fractol [ju] --> JULIA FRACTAL");
		ft_putendl("       ./fractol [bat] --> BATMAN FRACTAL");
		ft_putendl("       ./fractol [cel] --> CELTIC FRACTAL");
		ft_putendl("KEYS:  SCROLL == zoom in/out");
		ft_putendl("       R == reset");
		ft_putendl("       1 2 3 (on Pad) == change colors");
		ft_putendl("       F == 3D LAUNCHER");
		ft_putendl("       SPACEBAR == freeze");
		ft_putendl("USE ESC FOR FULL QUIT or USE WINDOW CROSS");
	}
	if (code == WMAP)
	{
		ft_putendl("WRONG FRACTAL");
		ft_error(PARAM);
	}
	exit(0);
}
