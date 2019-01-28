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

void	count_new_coordinates(t_map_mlx map)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < map.lines_nbr)
	{
		j = 0;
		while (j < map.columns_nbr)
		{
			map.arr_of_coordinates[i][j].x_new = map.arr_of_coordinates[i][j].x * 20;
			map.arr_of_coordinates[i][j].y_new = map.arr_of_coordinates[i][j].y * 20;
			map.arr_of_coordinates[i][j].color_new = 0xFFFFFF;
			j++;
		}
		i++;
	}
}


void	draw_net(t_map_mlx map)
{
	int 		i;
	int 		j;
	t_coordinates	start_h;
	t_coordinates	end_h;

	i = 0;
//	j = 0;
	while (i < map.lines_nbr - 1)
	{
		j = 0;
		while (j < map.columns_nbr - 1)
		{
//			printf("(%d,%d)     ", i, j);
			if (i == map.columns_nbr - 1 && j == map.columns_nbr - 1)
				break ;
			if (j != map.lines_nbr - 1)
			{
//				printf("adsfg\n");
				start_h.x = map.arr_of_coordinates[i][j].x * 20;
				start_h.y = map.arr_of_coordinates[i][j].y * 20;
				start_h.color = 0xFFFFFF; // add correct usage

				end_h.x = map.arr_of_coordinates[i][j].x * 20;
				end_h.y = (map.arr_of_coordinates[i][j].y + 1) * 20;
				end_h.color = 0xFFFFFF; // add correct usage
//				draw_line(&map.arr_of_coordinates[i][j], &map.arr_of_coordinates[i][j + 1], map);
				draw_line(&start_h, &end_h, map);
			}
			if (j != map.columns_nbr - 1)
			{
//				printf("1111111\n");
				start_h.x = map.arr_of_coordinates[i][j].x * 20;
				start_h.y = map.arr_of_coordinates[i][j].y * 20;
				start_h.color = 0xFFFFFF; // add correct usage

				end_h.x = (map.arr_of_coordinates[i][j].x + 1) * 20;
				end_h.y = map.arr_of_coordinates[i][j].y * 20;
				end_h.color = 0xFFFFFF; // add correct usage
//				draw_line(&map.arr_of_coordinates[i][j], &map.arr_of_coordinates[i + 1][j], map);
				draw_line(&start_h, &end_h, map);
			}
//			printf("%d      X: %d    Y:%d \n", num++, arr_of_coordinates[i][j].x, arr_of_coordinates[i][j].y);
//			printf("%d: %d -> %d: %d\n", start_h.x, start_h.y, end_h.x, end_h.y);
			j++;
		}
		printf("\n");
		i++;
	}
}
