/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:38:19 by yrudakev          #+#    #+#             */
/*   Updated: 2019/03/16 16:38:22 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_new_window(t_env *env, int weight, int height, char *title)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, weight, height, title);
}

void	ft_map_adaptation(t_env *env)
{
	int		width;
	int		height;
	double	size;

	width = (WINDOW_WIDTH + 100) / 2;
	height = (WINDOW_HEIGHT + 100) / 2;
	env->center.x == 0 ? env->center.x = 10 : env->center.x;
//	if (env->center.x == 0)
//		env->center.x = 10;
//	else
//		env->center.x;
	size = (width - 600) / (env->center.x);
	ft_find_translation(-env->center.x + width, -env->center.y + height, 0, env);
	ft_find_scale(size, env);
}

void		ft_find_translation(double x, double y, double z, t_env *env)
{
	t_matrix	*matrix_translation;

	matrix_translation = ft_matrice_translation(x, y, z);
	ft_matrix_calculation_for_all_points(matrix_translation, env);
	ft_center_of_map(env);
	free(matrix_translation);
}

void		ft_find_scale(double size, t_env *env)
{
	t_matrix *matrix_translation;

	matrix_translation = ft_matrix_scale(size);
	ft_matrix_calculation_for_all_points(matrix_translation, env);
	free(matrix_translation);
}