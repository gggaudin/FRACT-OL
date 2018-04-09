/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:46:53 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/07/15 14:27:27 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# define FALSE 0
# define TRUE 1
# define XWIN 800
# define YWIN 800

typedef struct		s_calc
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				k;
	int				xinc;
	int				yinc;
	int				cumul;
}					t_calc;

typedef	struct		s_fdf
{
	int				smy;
	int				smx;
	int				fy;
	int				ly;
	int				lx;
	int				fx;
	int				flagiso;
	char			*baninfo;
	char			*info;
	int				**tabmap;
	void			*mlx;
	void			*win;
	int				*data;
	int				bpp;
	int				flag;
	unsigned long	img_color;
	int				szline;
	int				endian;
	void			*img;
	int				alt1;
	int				alt2;
	int				alt3;
	int				alt4;
	int				alt5;
	int				alt6;
	int				alt7;
	int				xstart;
	int				ystart;
	int				para;
	int				lmap;
	int				hmap;
	int				**coorisx;
	int				**coorisy;
	int				**coorx;
	int				**coory;
	int				xspace;
	int				yspace;
	int				color;
}					t_fdf;

typedef struct		s_env
{
	int				pause;
	int				zoomact;
	void			*mlx;
	void			*win;
	char			*data;
	int				bpp;
	int				szline;
	int				endian;
	int				color;
	long double		zoom;
	long double		itmax;
	void			*img;
	int				map;
	int				**map3d;
	int				flagstr;
	int				buildmap;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				imagx;
	int				imagy;
	int				**colormap;
	int				indexcolor;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			i;
	int				x;
	int				y;
	int				mousemoved;
	int				act3d;
}					t_env;

enum
{
	PARAM,
	WMAP,
	MANDELBROT,
	JULIA,
	BATMAN,
	CELTIC,
};

void				findfly(int **map, t_env *e, t_fdf *f);
void				findlx(int **map, t_env *e, t_fdf *f);
void				findfx(int **map, t_env *e, t_fdf *f);
void				findly(int **map, t_env *e, t_fdf *f);
void				findfy(int **map, t_env *e, t_fdf *f);
void				xegment(t_fdf *f, int i, int j);
void				ft_initcalcx(t_calc *pts, t_fdf *f, int i, int j);
void				ft_initcalcy(t_calc *pts, t_fdf *f, int i, int j);
void				yegment(t_fdf *f, int i, int j);
int					redraw(t_fdf *f);
void				ft_dispinfo(t_fdf *f, int keycode);
void				ft_alt2(t_fdf *f, int keycode);
void				ft_alt(t_fdf *f, int keycode);
int					key_hook(int keycode, t_fdf *f);
int					*stockx(int x, int *tab, t_fdf *f);
int					*stocky(int k, int *tab, int z, t_fdf *f);
void				fill(t_fdf *f);
void				ft_dxdy(t_calc *pts, t_fdf *f);
void				ft_dydx(t_calc *pts, t_fdf *f);
void				initcolofdf(t_fdf *f, int i, int j);
void				fill(t_fdf *f);
void				calcptnxtpt(t_fdf *f, t_calc *pts, int i, int j);
void				calcptnxtl(t_fdf *f, t_calc *pts, int i, int j);
void				calcptcurr(t_fdf *f, t_calc *pts, int i, int j);
void				posy(t_fdf *f, int keycode);
void				posx(t_fdf *f, int keycode);
void				ft_chcolor(t_fdf *f, int keycode);
void				ft_zoom(t_fdf *f, int keycode, int flag);
void				ft_resetfdf(t_fdf *f);
void				chcolfract(int keycode, t_env *e);
void				locbat(t_env *e, int x, int y);
void				flagbat(int x, int y, t_env *e);
void				zoomout(t_env *e, int x, int y);
void				zoomin(t_env *e, int x, int y);
int					**colorbase(int **tab, t_env *e);
int					**colorfract(int **tab, t_env *e);
int					**colorpsyche(int **tab, t_env *e);
int					**colorvoodoo(int **tab, t_env *e);
int					**colorbatman(int **tab, t_env *e);
int					ft_checkcolor(int i, t_env *e);
void				putcolorpix(t_env *e);
void				drawfract(t_env *e);
void				choosecol(int i, t_env *e, int x, int y);
void				draw(t_fdf *f);
int					redraw(t_fdf *f);
void				ft_initcalcy(t_calc *pts, t_fdf *f, int i, int j);
void				pixel_put_to_image(t_fdf *f, int x, int y);
void				ft_info(t_fdf *f);
int					**ft_buildmap(int x, int y);
void				ft_fdf(int **map, t_env *e);
t_env				*ft_initceltic(t_env *e);
t_env				*ft_initbatman(t_env *e);
t_env				*ft_initjulia(t_env *e);
int					run_fract(char *av);
t_env				*ft_initbudda(t_env *e);
t_env				*ft_initmandel(t_env *e);
void				ft_celtic(t_env *e);
void				drawceltic(t_env *e);
void				drawbatman(t_env *e);
void				ft_batman(t_env *e);
int					**ft_initcolor(t_env *e);
int					ft_movemouse(int x, int y, t_env *e);
float				ft_calzoom(t_env *e);
int					ft_mousehook(int keycode, int x, int y, t_env *e);
int					ft_checkmap(char *av);
void				ft_error(int code);
void				ft_budda(t_env *e);
void				ft_mandelbrot(t_env *e);
void				ft_julia(t_env *e);
int					ft_keyhook(int keycode, t_env *e);
void				drawmandelbrot(t_env *e);
void				drawjulia(t_env *e);
void				drawbudda(t_env *e);

#endif
