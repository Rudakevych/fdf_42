/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:28:57 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/24 15:28:59 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_map(t_env *env)
{
	int			x;
	int			y;
	t_point		point1;

	y = 0;
	while (y < env->map->lenght)
	{
		x = 0;
		while (x < (env->map->lines[y]->len))
		{
			point1 = (*env->map->lines[y]->points[x]);
			if (env->map->lines[y]->points[x + 1])
				ft_draw_line(point1, (*env->map->lines[y]->points[x + 1]), env);
			if (env->map->lines[y + 1])
				if (env->map->lines[y + 1]->points[x] &&
					x <= env->map->lines[y + 1]->len)
					ft_draw_line(point1, (*env->map->lines[y + 1]->points[x]), env);
			x++;
		}
		y++;
	}
}
