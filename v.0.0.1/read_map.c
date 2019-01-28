/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:39:42 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/21 13:39:48 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_check_lines_number(int fd)
{
	char	*line;
	int		number_of_lines;

	number_of_lines = 0;
	while (get_next_line(fd, &line) == 1)
		number_of_lines++;
	return (number_of_lines);
}

int				ft_ft_check_columns_number(int fd)
{
	char	*line;
	int		number_of_columns;
	char	**columns;

	number_of_columns = 0;
	get_next_line(fd, &line);
	columns = ft_strsplit(line, ' ');
	while (columns[number_of_columns])
		number_of_columns++;
	return (number_of_columns);
}

t_coordinates	**ft_create_map(int lines_nbr, int columns_nbr)
{
	t_coordinates	**arr_of_coordinates;
	int				i;

	i = 0;
	arr_of_coordinates = (t_coordinates **)malloc(sizeof(t_coordinates *) * lines_nbr);
	while (i < lines_nbr)
	{
		arr_of_coordinates[i] = (t_coordinates *)malloc(sizeof(t_coordinates) * columns_nbr);
		i++;
	}
	return (arr_of_coordinates);
}

void			ft_add_coordinates_to_arr(char **coordinates, int x, int y, t_map_mlx map)
{
	while (coordinates[x])
	{
		map.arr_of_coordinates[x][y].x = x;
		map.arr_of_coordinates[x][y].y = y;
		map.arr_of_coordinates[x][y].z = ft_atoi(coordinates[x]);
		x++;
	}
}

int				ft_read_map(int fd, t_map_mlx map_mlx)
{
	char	*line;
	char	**coordinates;
	int		x;
	int		y;

	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		coordinates = ft_strsplit(line, ' ');
		ft_add_coordinates_to_arr(coordinates, x, y, map_mlx);
		free(line);
		ft_free_after_split(coordinates);
		y++;
	}
	return (1);
}
