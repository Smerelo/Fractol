/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:03:48 by smerelo           #+#    #+#             */
/*   Updated: 2018/05/07 19:01:35 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_coord		init_var(t_coord *point)
{
	point->max_iteration = 35;
	point->mult = 0;
	point->mult2 = 1;
	point->posx = 0;
	point->posy = 0;
	point->intervalx1 = -2.1;
	point->intervalx2 = 0.6;
	point->intervaly1 = -1.2;
	point->intervaly2 = 1.2;
	point->r1 = 1;
	point->r2 = 4;
	point->g1 = 1;
	point->g2 = 2;
	point->b1 = 0;
	point->b2 = 2;
	color(point);
	return (*point);
}

t_coord		init_var2(t_coord *point)
{
	point->max_iteration = 35;
	point->mult = 0;
	point->mult2 = 1;
	point->posx = 0.6;
	point->posy = 0;
	point->intervalx1 = -2.1;
	point->intervalx2 = 0.6;
	point->intervaly1 = -1.2;
	point->intervaly2 = 1.2;
	point->x0 = -0.8;
	point->y0 = 0.156;
	point->f = 1;
	point->r1 = 1;
	point->r2 = 4;
	point->g1 = 1;
	point->g2 = 2;
	point->b1 = 0;
	point->b2 = 2;
	color(point);
	return (*point);
}

int			choose_frac(t_coord *point)
{
	if (ft_strcmp(point->av, "mandelbrot") == 0)
	{
		init_var(point);
		point->f = 0;
		fractol(*point);
		return (1);
	}
	else if (ft_strcmp(point->av, "julia") == 0)
	{
		point->f = 1;
		init_var2(point);
		fractol2(*point);
		return (1);
	}
	if (ft_strcmp(point->av, "burning_ship") == 0)
	{
		point->f = 2;
		init_var(point);
		fractol3(*point);
		return (1);
	}
	return (0);
}

void		coloring(t_coord *point)
{
	point->c = point->iteration * point->color;
	if (point->iteration == point->max_iteration)
		point->img_string[point->j * 750 + point->i] = 0;
	else
		point->img_string[point->j * 750 + point->i] = point->c;
}
