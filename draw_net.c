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
	t_vector	start;
	t_vector	end;

	i = 0;
	while (i < (map.lines_nbr - 1))
	{
		j = 0;
		while (j < (map.columns_nbr - 1))
		{
			start.x = arr_of_coordinates[i][j].x;
			start.y = arr_of_coordinates[i][j].y;

			end.x = arr_of_coordinates[i + 1][j].x;
			end.y = arr_of_coordinates[i][j].y;

			draw_line(start, end, window); // vertical line
			draw_line(start, end, window); // horizontal line

			j++;
		}
		i++;
	}
}
