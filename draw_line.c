/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:54:37 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/22 16:54:40 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/*
** draw line used Bresenham's line algorithm
** https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
*/

void	draw_line_down(t_d_s_points ds_points, t_vector strt, t_window window)
{
	int		d;
	int		d1;
	int		d2;
	int		x;
	int		y;

	x = strt.x + ds_points.sx;
	y = strt.y;
	d = (ds_points.dy << 1) - ds_points.dx;
	d1 = ds_points.dy << 1;
	d2 = (ds_points.dy - ds_points.dx) << 1;
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, strt.x, strt.y, strt.color);
	while (ds_points.i <= ds_points.dx)
	{
		if (d > 0)
		{
			d += d2;
			y += ds_points.sy;
		}
		else
			d += d1;
		mlx_pixel_put(window.mlx_ptr, window.win_ptr, x, y, strt.color);
		ds_points.i++;
		x += ds_points.sx;
	}
}

void	draw_line_up(t_d_s_points ds_points, t_vector strt, t_window window)
{
	int d;
	int d1;
	int d2;
	int y;
	int x;

	y = strt.y + ds_points.sy;
	x = strt.x;
	d = (ds_points.dx << 1) - ds_points.dy;
	d1 = ds_points.dx << 1;
	d2 = (ds_points.dx - ds_points.dy) << 1;
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, strt.x, strt.y, strt.color);
	while (ds_points.i <= ds_points.dy)
	{
		if (d > 0)
		{
			d += d2;
			x += ds_points.sx;
		}
		else
			d += d1;
		mlx_pixel_put(window.mlx_ptr, window.win_ptr, x, y, strt.color);
		ds_points.i++;
		y += ds_points.sy;
	}
}

void	draw_line(t_vector start, t_vector end, t_window window)
{
	t_d_s_points	ds_points;

	ds_points.dx = abs(end.x - start.x);
	ds_points.dy = abs(end.y - start.y);
	ds_points.sx = end.x >= start.x ? 1 : -1;
	ds_points.sy = end.y >= start.y ? 1 : -1;
	ds_points.i = 1;
	if (ds_points.dy <= ds_points.dx)
		draw_line_down(ds_points, start, window);
	else
		draw_line_up(ds_points, start, window);
}
