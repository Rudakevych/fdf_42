/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_in_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:06:37 by yrudakev          #+#    #+#             */
/*   Updated: 2019/03/16 17:06:39 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_matrice_translation(double x_point, double y_point, double z_point)
{
	t_matrix	*maxtix;

	if (!(maxtix = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	maxtix->a4 = x_point;
	maxtix->b4 = y_point;
	maxtix->c4 = z_point;
	maxtix->a1 = 1;
	maxtix->b2 = 1;
	maxtix->c3 = 1;
	maxtix->d4 = 1;
	return (maxtix);
}

t_matrix	*ft_matrix_scale(double scale)
{
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	matrix->a1 = scale;
	matrix->b2 = scale;
	matrix->c3 = scale;
	matrix->d4 = 1;
	return (matrix);
}

static void	ft_matrix_calculaton(t_point *p, t_matrix *m, t_env *e)
{
	double tmp_x;
	double tmp_y;
	double tmp_z;

	p->x -= e->center.x;
	p->y -= e->center.y;
	tmp_x = p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	tmp_y = p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	tmp_z = p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;
	p->z = tmp_z;
	p->y = tmp_y;
	p->x = tmp_x;
	p->x += e->center.x;
	p->y += e->center.y;
}

static void	ft_matrix_calculation_for_all_points(t_matrix *m, t_env *e)
{
	int x;
	int y;

	y = 0;
	while (y < e->map->lenght)
	{
		x = 0;
		while (x < (e->map->lines[y]->len))
		{
			ft_matrix_calculaton(e->map->lines[y]->points[x], m, e);
			x++;
		}
		y++;
	}
}

