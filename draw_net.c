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

void	draw_net(t_map map, t_window window, t_coordinates	**arr_of_coordinates)
{
	int 		i;
	int 		j;
	t_vector	start_h;
	t_vector	end_h;

	i = 0;
	while (i < (map.lines_nbr - 1))
	{
		j = 0;
		while (j < (map.columns_nbr - 1))
		{
			if (j != (map.columns_nbr - 1))
			{
				start_h.x = arr_of_coordinates[i][j].x * 10;
				start_h.y = arr_of_coordinates[i][j].y * 10;
				start_h.color = 0xFFFFFF; // add correct usage

				end_h.x = arr_of_coordinates[i][j].x * 10;
				end_h.y = (arr_of_coordinates[i][j].y + 1) * 10;
				end_h.color = 0xFFFFFF; // add correct usage
				draw_line(start_h, end_h, window);
			}
			if (j != (map.lines_nbr - 1))
			{
				start_h.x = arr_of_coordinates[i][j].x * 10;
				start_h.y = arr_of_coordinates[i][j].y * 10;
				start_h.color = 0xFFFFFF; // add correct usage

				end_h.x = (arr_of_coordinates[i][j].x + 1) * 10;
				end_h.y = arr_of_coordinates[i][j].y * 10;
				end_h.color = 0xFFFFFF; // add correct usage
				draw_line(start_h, end_h, window);
			}
//			printf("%d: %d -> %d: %d\n", start_h.x, start_h.y, end_h.x, end_h.y);
			j++;
		}
		i++;
	}
}
