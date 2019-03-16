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

void	draw_net(t_map_mlx map)
{
	int 		i;
	int 		j;
	t_coordinates	start_h;
	t_coordinates	end_h;

	i = 0;
	while (i < map.columns_nbr)
	{
		j = 0;
		while (j < map.lines_nbr)
		{
			if ((i == map.columns_nbr - 2) && (j == map.columns_nbr - 2))
				break ;
			if (j != map.lines_nbr - 2)
			{
				start_h.x = map.arr_of_coordinates[i][j].x * 20;
				start_h.y = map.arr_of_coordinates[i][j].y * 20;
				start_h.color = 0xFFFFFF; // add correct usage
				end_h.x = map.arr_of_coordinates[i][j].x * 20;
				end_h.y = (map.arr_of_coordinates[i][j].y + 1) * 20;
				end_h.color = 0xFFFFFF; // add correct usage
				draw_line(&start_h, &end_h, map);
//				ft_draw_line(&map.arr_of_coordinates[i][j], &map.arr_of_coordinates[i][j + 1], map);
			}
			if (i != map.columns_nbr - 2)
			{
				start_h.x = map.arr_of_coordinates[i][j].x * 20;
				start_h.y = map.arr_of_coordinates[i][j].y * 20;
				start_h.color = 0xFFFFFF; // add correct usage
				end_h.x = (map.arr_of_coordinates[i][j].x + 1) * 20;
				end_h.y = map.arr_of_coordinates[i][j].y * 20;
				end_h.color = 0xFFFFFF; // add correct usage
				draw_line(&start_h, &end_h, map);
//				ft_draw_line(&map.arr_of_coordinates[i][j], &map.arr_of_coordinates[i + 1][j], map);
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

void	rotate_by_z(t_map_mlx map)
{
	int 	i;
	int 	j;
	double 	angle;

	i = 0;
	angle = 5;
	while (i < map.columns_nbr)
	{
		j = 0;
		while (j < map.lines_nbr)
		{
			map.arr_of_coordinates[i][j].x_new = (int)(map.arr_of_coordinates[i][j].x * cos(angle)) - (int)(map.arr_of_coordinates[i][j].y * sin(angle));
			map.arr_of_coordinates[i][j].y_new = (int)(map.arr_of_coordinates[i][j].x * sin(angle)) + (int)(map.arr_of_coordinates[i][j].y * cos(angle));
			j++;
		}
		i++;
	}
}

void	draw_net_3d(t_map_mlx map)
{
    int 		i;
    int 		j;
    t_coordinates	start_h;
    t_coordinates	end_h;

    i = 0;
	rotate_by_z(map);
    while (i < map.columns_nbr)
    {
        j = 0;
        while (j < map.lines_nbr)
        {
            if ((i == map.columns_nbr - 1) && (j == map.columns_nbr - 1))
                break ;
            if (j != map.lines_nbr - 2)
            {
                start_h.x = map.arr_of_coordinates[i][j].x_new * 20;
                start_h.y = map.arr_of_coordinates[i][j].y_new * 20;
                start_h.color = 0xFFFFFF; // add correct usage

                end_h.x = map.arr_of_coordinates[i][j].x_new * 20;
                end_h.y = (map.arr_of_coordinates[i][j].y_new + 1) * 20;
                end_h.color = 0xFFFFFF; // add correct usage
                draw_line(&start_h, &end_h, map);

//				ft_draw_line(&map.arr_of_coordinates[i][j], &map.arr_of_coordinates[i][j + 1], map);
            }
            if (i != map.columns_nbr - 2)
            {
                start_h.x = map.arr_of_coordinates[i][j].x_new * 20;
                start_h.y = map.arr_of_coordinates[i][j].y_new * 20;
                start_h.color = 0xFFFFFF; // add correct usage

                end_h.x = (map.arr_of_coordinates[i][j].x_new + 1) * 20;
                end_h.y = map.arr_of_coordinates[i][j].y_new * 20;
                end_h.color = 0xFFFFFF; // add correct usage
                draw_line(&start_h, &end_h, map);

//				ft_draw_line(&map.arr_of_coordinates[i][j], &map.arr_of_coordinates[i + 1][j], map);
            }
//			printf("%d      X: %d    Y:%d \n", num++, arr_of_coordinates[i][j].x, arr_of_coordinates[i][j].y);
//			printf("%d: %d -> %d: %d\n", start_h.x, start_h.y, end_h.x, end_h.y);
            j++;
        }
        printf("\n");
        i++;
    }
}
