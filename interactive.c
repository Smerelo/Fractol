/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 20:31:40 by smerelo           #+#    #+#             */
/*   Updated: 2018/05/12 19:48:59 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	interactive3(int keycode, t_coord *point)
{
	if (keycode == 124)
		point->posx += 1 / point->mult2;
	if (keycode == 0)
		point->x0 -= 0.007;
	if (keycode == 83)
	{
		point->f2 = 0;
		red(point);
	}
	if (keycode == 84)
	{
		point->f2 = 0;
		green(point);
	}
	if (keycode == 85)
	{
		point->f2 = 0;
		blue(point);
	}
	if (keycode == 86)
	{
		point->f2 = 1;
		red(point);
	}
}

void	interactive2(int keycode, t_coord *point)
{
	if (keycode == 69)
	{
		point->mult += 0.3;
		point->mult2 *= 1.15;
	}
	if (keycode == 78)
	{
		point->mult -= 0.3;
		if (point->mult2 + 0.05 > 1)
			point->mult2 /= 1.15;
	}
	if (keycode == 126)
		point->posy -= 1 / point->mult2;
	if (keycode == 13)
		point->y0 += 0.007;
	if (keycode == 123)
		point->posx -= 1 / point->mult2;
	if (keycode == 2)
		point->x0 += 0.007;
	if (keycode == 125)
		point->posy += 1 / point->mult2;
	if (keycode == 1)
		point->y0 -= 0.007;
	interactive3(keycode, point);
}

int		interactive(int keycode, t_coord *point)
{
	interactive1(keycode, point);
	interactive2(keycode, point);
	if (keycode == 87)
	{
		point->f2 = 1;
		green(point);
	}
	if (keycode == 88)
	{
		point->f2 = 1;
		blue(point);
	}
	if (keycode == 67)
		point->max_iteration += 1;
	if (keycode == 75)
		point->max_iteration -= 1;
	mlx_destroy_image(point->mlx, point->img);
	point->img = mlx_new_image(point->mlx, 750, 750);
	if (point->f == 0)
		fractol(*point);
	else if (point->f == 1)
		fractol2(*point);
	else if (point->f == 2)
		fractol3(*point);
	return (0);
}

int		mouse_interactive(int x, int y, t_coord *point)
{
	point->x0 = (((x - 375) * 2.7) / 750);
	point->y0 = (((y - 375) * 2.4) / 750);
	mlx_destroy_image(point->mlx, point->img);
	point->img = mlx_new_image(point->mlx, 750, 750);
	if (point->f == 0)
		fractol(*point);
	else if (point->f == 1)
		fractol2(*point);
	return (0);
}

int		scroll(int button, int x, int y, t_coord *point)
{
	x = y;
	if (button == 5)
	{
		point->mult += 0.3;
		point->mult2 *= 1.15;
	}
	if (button == 4)
	{
		if (point->mult - 0.3 > 0)
		{
			point->mult -= 0.3;
			point->mult2 /= 1.15;
		}
	}
	mlx_destroy_image(point->mlx, point->img);
	point->img = mlx_new_image(point->mlx, 750, 750);
	if (point->f == 0)
		fractol(*point);
	else if (point->f == 1)
		fractol2(*point);
	else if (point->f == 2)
		fractol3(*point);
	return (0);
}
