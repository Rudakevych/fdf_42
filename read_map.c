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

int		ft_check_lines_number(int fd)
{
	char	*line;
	int		number_of_lines;

	number_of_lines = 0;
	while (get_next_line(fd, &line) == 1)
		number_of_lines++;
	return (number_of_lines);
}

int		ft_ft_check_columns_number(int fd)
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

void	ft_add_coordinates_to_arr(char **coordinates, int x, int y, t_coordinates **arr_of_coordinates)
{
	while (coordinates[x])
	{
		arr_of_coordinates[x][y].x = x;
		arr_of_coordinates[x][y].y = y;
		arr_of_coordinates[x][y].z = ft_atoi(coordinates[x]);
		x++;
	}
}

int		ft_read_map(int fd, t_map_mlx *mlx)
{
	char	*line;
	char	**coordinates;
	int		x;
	int		y;

	y = 0;
	mlx->arr_of_coordinates = (t_coordinates **)malloc(sizeof(t_coordinates *) * mlx->lines_nbr);
	while (y < mlx->lines_nbr)
	{
		mlx->arr_of_coordinates[y] = (t_coordinates *)malloc(sizeof(t_coordinates) * mlx->columns_nbr);
		y++;
	}
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		coordinates = ft_strsplit(line, ' ');
		ft_add_coordinates_to_arr(coordinates, x, y, mlx->arr_of_coordinates);
		free(line);
		ft_free_after_split(coordinates);
		y++;
	}
	return (1);
}
