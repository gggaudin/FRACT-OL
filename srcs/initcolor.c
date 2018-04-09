/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 08:53:37 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/07 12:08:57 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		**colorbase(int **tab, t_env *e)
{
	tab[0][0] = mlx_get_color_value(e->mlx, 0x00010101);
	tab[0][1] = mlx_get_color_value(e->mlx, 0x000C6DE8);
	tab[0][2] = mlx_get_color_value(e->mlx, 0x000D38FF);
	tab[0][3] = mlx_get_color_value(e->mlx, 0x000C6DE9);
	tab[0][4] = mlx_get_color_value(e->mlx, 0x00FE0055);
	tab[0][5] = mlx_get_color_value(e->mlx, 0x000CE1E8);
	tab[0][6] = mlx_get_color_value(e->mlx, 0x000DFFC3);
	tab[0][7] = mlx_get_color_value(e->mlx, 0x00010101);
	return (tab);
}

int		**colorfract(int **tab, t_env *e)
{
	tab[2][0] = mlx_get_color_value(e->mlx, 0x00010101);
	tab[2][1] = mlx_get_color_value(e->mlx, 0x00FDF48B);
	tab[2][2] = mlx_get_color_value(e->mlx, 0x00A96000);
	tab[2][3] = mlx_get_color_value(e->mlx, 0x001A0A0B);
	tab[2][4] = mlx_get_color_value(e->mlx, 0x004C9F6B);
	tab[2][5] = mlx_get_color_value(e->mlx, 0x00FCFDD3);
	tab[2][6] = mlx_get_color_value(e->mlx, 0x00FDFFF7);
	tab[2][7] = mlx_get_color_value(e->mlx, 0x00010101);
	return (tab);
}

int		**colorpsyche(int **tab, t_env *e)
{
	tab[1][0] = mlx_get_color_value(e->mlx, 0x00010101);
	tab[1][1] = mlx_get_color_value(e->mlx, 0x008A1B78);
	tab[1][2] = mlx_get_color_value(e->mlx, 0x001E2A7D);
	tab[1][3] = mlx_get_color_value(e->mlx, 0x000492C8);
	tab[1][4] = mlx_get_color_value(e->mlx, 0x00009342);
	tab[1][5] = mlx_get_color_value(e->mlx, 0x00F4F003);
	tab[1][6] = mlx_get_color_value(e->mlx, 0x00DA2623);
	tab[1][7] = mlx_get_color_value(e->mlx, 0x00010101);
	return (tab);
}

int		**colorvoodoo(int **tab, t_env *e)
{
	tab[3][0] = mlx_get_color_value(e->mlx, 0x00010101);
	tab[3][1] = mlx_get_color_value(e->mlx, 0x00CE440B);
	tab[3][2] = mlx_get_color_value(e->mlx, 0x0097182E);
	tab[3][3] = mlx_get_color_value(e->mlx, 0x00BC219C);
	tab[3][4] = mlx_get_color_value(e->mlx, 0x002322C2);
	tab[3][5] = mlx_get_color_value(e->mlx, 0x0007B486);
	tab[3][6] = mlx_get_color_value(e->mlx, 0x0079AC050);
	tab[3][7] = mlx_get_color_value(e->mlx, 0x00010101);
	return (tab);
}

int		**colorbatman(int **tab, t_env *e)
{
	tab[4][0] = mlx_get_color_value(e->mlx, 0x00010101);
	tab[4][1] = mlx_get_color_value(e->mlx, 0x00FFDE00);
	tab[4][2] = mlx_get_color_value(e->mlx, 0x00FFDE00);
	tab[4][3] = mlx_get_color_value(e->mlx, 0x00FFDE00);
	tab[4][4] = mlx_get_color_value(e->mlx, 0x00FFDE00);
	tab[4][5] = mlx_get_color_value(e->mlx, 0x00FFDE00);
	tab[4][6] = mlx_get_color_value(e->mlx, 0x00FFDE00);
	tab[4][7] = mlx_get_color_value(e->mlx, 0x00010101);
	return (tab);
}
