/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:51:25 by smerelo           #+#    #+#             */
/*   Updated: 2018/05/07 19:01:36 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_coord			color(t_coord *point)
{
	point->color = (point->r2 * pow(16, 5)) + (point->r1 * pow(16, 4)) +
	(point->g2 * pow(16, 3)) + (point->g1 * pow(16, 2)) +
	(point->b2 * pow(16, 1)) + (point->b1 * pow(16, 0));
	return (*point);
}

int				red(t_coord *point)
{
	point->f2 == 0 ? point->r1++ : point->r1--;
	if (point->r1 > 15 || point->r1 < 0)
	{
		point->r1 = 0;
		point->f2 == 0 ? point->r2++ : point->r2--;
	}
	if (point->r2 > 15 || point->r2 < 0)
	{
		point->r2 = 0;
		point->r1 = 0;
	}
	color(point);
	return (point->color);
}

int				blue(t_coord *point)
{
	point->f2 == 0 ? point->b1++ : point->b1--;
	if (point->b1 > 15 || point->b1 < 0)
	{
		point->b1 = 0;
		point->b2 == 0 ? point->r2++ : point->b2--;
	}
	if (point->b2 > 15 || point->b2 < 0)
	{
		point->b2 = 0;
		point->b1 = 0;
	}
	color(point);
	return (point->color);
}

int				green(t_coord *point)
{
	point->f2 == 0 ? point->g1++ : point->g1--;
	if (point->g1 > 15 || point->g1 < 0)
	{
		point->g1 = 0;
		point->g2 == 0 ? point->g2++ : point->g2--;
	}
	if (point->g2 > 15 || point->g2 < 0)
	{
		point->g2 = 0;
		point->g1 = 0;
	}
	color(point);
	return (point->color);
}

void			interactive1(int keycode, t_coord *point)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 19)
		init_var2(point);
	if (keycode == 18)
	{
		init_var(point);
		point->f = 0;
	}
	if (keycode == 20)
	{
		init_var(point);
		point->f = 2;
	}
	if (keycode == 82 && (point->f == 0 || point->f == 2))
		init_var(point);
	if (keycode == 82 && point->f == 1)
		init_var2(point);
}
