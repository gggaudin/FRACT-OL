/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:21:29 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/06/12 08:29:14 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_checkmap(char *av)
{
	if (ft_strncmp("ma\0", av, 3) == 0)
		return (MANDELBROT);
	if (ft_strncmp("ju\0", av, 3) == 0)
		return (JULIA);
	if (ft_strncmp("bat\0", av, 4) == 0)
		return (BATMAN);
	if (ft_strncmp("cel\0", av, 4) == 0)
		return (CELTIC);
	return (0);
}
