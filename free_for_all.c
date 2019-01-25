/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:23:02 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/22 11:23:13 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_after_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
}

void	ft_free_arr_of_coordinates(t_map_mlx *mlx)
{
	int i;

	i = 0;
	while (mlx->arr_of_coordinates[i] != NULL)
	{
		free(mlx->arr_of_coordinates[i]);
		i++;
	}
	free(mlx->arr_of_coordinates[i]);
}