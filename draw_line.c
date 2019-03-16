/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                        :+:      :+:    :+:   */
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



static void		draw_line_params(t_point *point1, t_point *point2, double *tab)
{
	tab[0] = fabs(point1->x - point2->x);
	tab[1] = point1->x < point2->x ? 1 : -1;
	tab[2] = fabs(point1->y - point2->y);
	tab[3] = point1->y < point2->y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void		draw_point(t_point *point, t_env *e, int color)
{
	int i;

	i = ((int)point->x * 4) + ((int)point->y * e->s_line);
	e->pixel_img[i] = color;
	e->pixel_img[++i] = color >> 8;
	e->pixel_img[++i] = color >> 16;
}

static void		ft_draw_line(t_point point1, t_point point2, t_env *env)
{
	double	tab[6];
	int		state;

	if (!point_out_window(&point1) && !point_out_window(&point2))
		return ;
	draw_line_params(&point1, &point2, tab), state = 1;
	while (state == 1 && !((int)point1.x == (int)point2.x && (int)point1.y == (int)point2.y))
	{
		if (point_out_window(&point1) == 1)
			draw_point(&point1, env, get_color(&point1, &point2));
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)point1.x != (int)point2.x)
		{
			tab[4] -= tab[2];
			point1.x += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)point1.y != (int)point2.y)
		{
			tab[4] += tab[0];
			point1.y += tab[3];
			state = 1;
		}
	}
}


//void	draw_line_down(t_d_s_points ds_points, t_coordinates *strt, t_map_mlx mlx)
//{
//	int		d;
//	int		d1;
//	int		d2;
//	int		x;
//	int		y;
//
//	x = strt->x + ds_points.sx;
//	y = strt->y;
//	d = (ds_points.dy << 1) - ds_points.dx;
//	d1 = ds_points.dy << 1;
//	d2 = (ds_points.dy - ds_points.dx) << 1;
//	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, strt->x + 200, strt->y + 200, strt->color);
//	while (ds_points.i <= ds_points.dx)
//	{
//		if (d > 0)
//		{
//			d += d2;
//			y += ds_points.sy;
//		}
//		else
//			d += d1;
//		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x + 200, y + 200, strt->color);
//		ds_points.i++;
//		x += ds_points.sx;
//	}
//}
//
//void	draw_line_up(t_d_s_points ds_points, t_coordinates *strt, t_map_mlx mlx)
//{
//	int d;
//	int d1;
//	int d2;
//	int y;
//	int x;
//
//	y = strt->y + ds_points.sy;
//	x = strt->x;
//	d = (ds_points.dx << 1) - ds_points.dy;
//	d1 = ds_points.dx << 1;
//	d2 = (ds_points.dx - ds_points.dy) << 1;
//	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, strt->x + 200, strt->y + 200, strt->color);
//	while (ds_points.i <= ds_points.dy)
//	{
//		if (d > 0)
//		{
//			d += d2;
//			x += ds_points.sx;
//		}
//		else
//			d += d1;
//		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x + 200, y + 200, strt->color);
//		ds_points.i++;
//		y += ds_points.sy;
//	}
//}
//
//void	ft_draw_line(t_coordinates *start, t_coordinates *end, t_map_mlx mlx)
//{
//	t_d_s_points	ds_points;
//
//	ds_points.dx = abs(end->x - start->x);
//	ds_points.dy = abs(end->y - start->y);
//	ds_points.sx = end->x >= start->x ? 1 : -1;
//	ds_points.sy = end->y >= start->y ? 1 : -1;
//	ds_points.i = 1;
//	if (ds_points.dy <= ds_points.dx)
//		draw_line_down(ds_points, start, mlx);
//	else
//		draw_line_up(ds_points, start, mlx);
//}
