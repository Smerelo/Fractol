/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:02:28 by smerelo           #+#    #+#             */
/*   Updated: 2018/05/07 20:48:53 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# include "mlx.h"

typedef struct	s_coord
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_string;
	int		bpp;
	int		s_l;
	int		endian;
	double	x;
	double	y;
	double	zoom;
	double	zoomx;
	double	zoomy;
	int		iteration;
	double	x0;
	double	y0;
	double	intervalx1;
	double	intervalx2;
	double	intervaly1;
	double	intervaly2;
	int		max_iteration;
	int		f2;
	double	posx;
	double	posy;
	double	temp;
	int		i;
	int		j;
	int		color;
	double	mult;
	double	mult2;
	double	f;
	double	index;
	char	*av;
	double	c;
	int		xm;
	int		ym;
	int		r1;
	int		r2;
	int		g1;
	int		g2;
	int		b1;
	int		b2;
}				t_coord;

int				interactive(int key, t_coord *point);
t_coord			fractol(t_coord point);
t_coord			fractol2(t_coord point);
t_coord			fractol3(t_coord point);
t_coord			init_var(t_coord *point);
t_coord			init_var2(t_coord *point);
int				choose_frac(t_coord *point);
int				mouse_interactive(int x, int y, t_coord *point);
int				scroll(int button, int x, int y, t_coord *point);
t_coord			color(t_coord *point);
int				red(t_coord *point);
int				green(t_coord *point);
void			interactive1(int keycode, t_coord *point);
void			coloring(t_coord *point);
int				blue(t_coord *point);
#endif
