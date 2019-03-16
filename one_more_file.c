/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_more_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:25:20 by yrudakev          #+#    #+#             */
/*   Updated: 2019/03/16 16:25:22 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center_of_map(t_env *env)
{
	t_point		point;
	int			ylen;
	int			xlen;

	point = env->center;
	ylen = env->map->lenght;
	xlen = env->map->lines[ylen - 1]->len;
	point.x = (env->map->lines[ylen - 1]->points[xlen - 1]->x +
		   env->map->lines[0]->points[0]->x) / 2;
	point.y = (env->map->lines[ylen - 1]->points[xlen - 1]->y +
		   env->map->lines[0]->points[0]->y) / 2;
	env->center = point;
}
