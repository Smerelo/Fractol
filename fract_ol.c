/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:01:53 by smerelo           #+#    #+#             */
/*   Updated: 2018/05/12 19:42:14 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_coord			extra(t_coord point)
{
	point.zoom = 750 + pow(2, point.mult);
	point.i = -1;
	point.zoomx = (point.zoom) / (point.intervalx2 - point.intervalx1);
	point.zoomy = (point.zoom) / (point.intervaly2 - point.intervaly1);
	return (point);
}

t_coord			fractol3(t_coord point)
{
	point = extra(point);
	while (++point.i < 750)
	{
		point.x0 = point.i / point.zoomx + point.intervalx1 + point.posx;
		point.j = -1;
		while (++point.j < 750)
		{
			point.x = 0;
			point.y = 0;
			point.y0 = point.j / point.zoomy + point.intervaly1 + point.posy;
			point.iteration = 0;
			while (point.x * point.x + point.y * point.y
					< 4 && point.iteration < point.max_iteration)
			{
				point.temp = point.x * point.x - point.y * point.y + point.x0;
				point.y = fabs(2 * point.x * point.y) + point.y0;
				point.x = fabs(point.temp);
				point.iteration++;
			}
			coloring(&point);
		}
	}
	mlx_put_image_to_window(point.mlx, point.win, point.img, 0, 0);
	return (point);
}

t_coord			fractol(t_coord point)
{
	point = extra(point);
	while (++point.i < 750)
	{
		point.x0 = point.i / point.zoomx + point.intervalx1 + point.posx;
		point.j = -1;
		while (++point.j < 750)
		{
			point.x = 0;
			point.y = 0;
			point.y0 = point.j / point.zoomy + point.intervaly1 + point.posy;
			point.iteration = 0;
			while (point.x * point.x + point.y * point.y
					< 4 && point.iteration < point.max_iteration)
			{
				point.temp = point.x * point.x - point.y * point.y + point.x0;
				point.y = 2 * point.x * point.y + point.y0;
				point.x = point.temp;
				point.iteration++;
			}
			coloring(&point);
		}
	}
	mlx_put_image_to_window(point.mlx, point.win, point.img, 0, 0);
	return (point);
}

t_coord			fractol2(t_coord point)
{
	point = extra(point);
	while (++point.i < 750)
	{
		point.j = -1;
		while (++point.j < 750)
		{
			point.x = point.i / point.zoomx + point.intervalx1 + point.posx;
			point.y = point.j / point.zoomy + point.intervaly1 + point.posy;
			point.iteration = 0;
			while (point.x * point.x + point.y * point.y
					< 4 && point.iteration < point.max_iteration)
			{
				point.temp = point.x * point.x - point.y * point.y + point.x0;
				point.y = 2 * point.x * point.y + point.y0;
				point.x = point.temp;
				point.iteration++;
			}
			coloring(&point);
		}
	}
	mlx_put_image_to_window(point.mlx, point.win, point.img, 0, 0);
	return (point);
}

int				main(int ac, char **av)
{
	t_coord point;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") != 0
				&& ft_strcmp(av[1], "julia") != 0
				&& ft_strcmp(av[1], "burning_ship") != 0))
	{
		ft_putendl("Intput error:\nmandelbrot\njulia\nburning_ship");
		return (0);
	}
	point.av = av[1];
	point.mlx = mlx_init();
	point.win = mlx_new_window(point.mlx, 750, 750, "fract_ol");
	point.img = mlx_new_image(point.mlx, 750, 750);
	point.img_string = (int*)mlx_get_data_addr(point.img, &(point.bpp),
			&(point.s_l), &(point.endian));
	choose_frac(&point);
	mlx_hook(point.win, 2,
			(1L << 0), interactive, (void *)&point);
	mlx_hook(point.win, 6, (1L << 6), mouse_interactive, &point);
	mlx_mouse_hook(point.win, scroll, &point);
	mlx_loop(point.mlx);
	return (0);
}
