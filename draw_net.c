/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:17:33 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/22 13:17:42 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** draw 2D net by x/y coordinates
*/

//void	draw_net(t_map_mlx mlx, t_coordinates	**arr_of_coordinates)
//{
//	int 		i;
//	int 		j;
//
//	i = 0;
//	j = 0;
//	while (i < mlx.lines_nbr)
//	{
//		j = 0;
//		while (j < mlx.columns_nbr)
//		{
//			if (i == mlx.columns_nbr && j == mlx.columns_nbr)
//				break ;
//			if (j != mlx.columns_nbr - 1)
//			{
//				draw_line(mlx, end_h, mlx);
//			}
//			if (j != mlx.lines_nbr - 1)
//			{
//				draw_line(start_h, end_h, mlx);
//			}
////			printf("%d      X: %d    Y:%d \n", num++, arr_of_coordinates[i][j].x, arr_of_coordinates[i][j].y);
////			printf("%d: %d -> %d: %d\n", start_h.x, start_h.y, end_h.x, end_h.y);
//			j++;
//		}
//		i++;
//	}
//}
