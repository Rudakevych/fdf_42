/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:39:11 by yrudakev          #+#    #+#             */
/*   Updated: 2019/03/16 17:39:15 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *env)
{
	draw_reload(env);
	return (0);
}

void	draw_reload(t_env *env)
{
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH + 100, WINDOW_HEIGHT + 100);
	env->pixel_img = mlx_get_data_addr(env->img, &(env->bpp), &(env->s_line), &(env->ed));
	ft_draw_map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, -50, -50);
	mlx_destroy_image(env->mlx, env->img);
}

static	void	key_hook_rotation(int keycode, t_env *e)
{
	if (keycode == KEY_ROT_X_U)
		ft_cal_rotation(e, MOVE_ROT_X_U, 'x');
	else if (keycode == KEY_ROT_X_D)
		ft_cal_rotation(e, MOVE_ROT_X_D, 'x');
	else if (keycode == KEY_ROT_Y_U)
		ft_cal_rotation(e, MOVE_ROT_Y_U, 'y');
	else if (keycode == KEY_ROT_Y_D)
		ft_cal_rotation(e, MOVE_ROT_Y_D, 'y');
	else if (keycode == KEY_ROT_Z_U)
		ft_cal_rotation(e, MOVE_ROT_Z_U, 'z');
	else if (keycode == KEY_ROT_Z_D)
		ft_cal_rotation(e, MOVE_ROT_Z_D, 'z');
}

static	void	key_hook_translation(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
//		ft_cal_translat(e, 0, MOVE_UP, 0);
	else if (keycode == KEY_DOWN)
		ft_cal_translat(e, 0, MOVE_DOWN, 0);
	else if (keycode == KEY_LEFT)
		ft_cal_translat(e, MOVE_LEFT, 0, 0);
	else if (keycode == KEY_RIGHT)
		ft_cal_translat(e, MOVE_RIGHT, 0, 0);
}

static	void	key_hook_scale(int keycode, t_env *e)
{
	if (keycode == KEY_ZOOM_IN)
		ft_cal_scale(e, MOVE_ZOOM_IN);
	else if (keycode == KEY_ZOOM_OUT)
		ft_cal_scale(e, MOVE_ZOOM_OUT);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	key_hook_rotation(keycode, e);
	key_hook_translation(keycode, e);
	key_hook_scale(keycode, e);
	draw_reload(e);
	return (0);
}