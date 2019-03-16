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

int		ft_getnumber(char *str)
{
	int		is_negative;
	int		number;

	is_negative = 0;
	if (str[0] == '-')
		is_negative = 1, str++;
	number = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		number = (number * 10) + *str++ - '0';
	}
	return ((is_negative == 1) ? -number : number);
}

int		ft_point(char *line, int line_number, t_point ***points_arr)
{
	char		**str_arr;
	t_point		*point;
	int			i;

	str_arr = ft_strsplit(line, ' ');
	i = 0;
	while (str_arr[i] != 0)
		i++;
	if (!((*points_arr) = (t_point **)malloc(sizeof(t_point) * i)))
		ft_error_malloc();
	i = 0;
	while (str_arr[i] != 0)
	{
		point = (t_point *)malloc(sizeof(t_point));
		point->x = i * WIDTH;
		point->y = line_number * HEIGHT;
		point->z = ft_getnumber(str_arr[i]);
		point->s = 1;
		point->z_color = point->z;
		(*points_arr)[i] = point;
		i++;
	}
	return (i);
}

int		ft_map_line(char *map)
{
	int		fd;
	int		nb_lines;
	char	buf;

	fd = 0;
	nb_lines = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		ft_error_fd();
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nb_lines++;
	}
	close(fd);
	return (nb_lines);
}

t_map	*ft_read_map(int fd, char **argv)
{
	char		*line;
	int			line_number;
	t_map		*map;
	t_line		*map_line;
	t_point		**array_points;

	line_number = 0;
	map->lenght = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))) ||
		!(map->lines = (t_line **)malloc(sizeof(t_line) *
				ft_map_line(argv[1]))))
		ft_error_malloc();
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(map_line = (t_line *)malloc(sizeof(t_line))))
				ft_error_malloc();
			map_line->len = ft_point(line, line_number, &array_points);
			map_line->points = array_points;
			map->lines[line_number] = map_line;
			line_number++;
		}
		map->lenght = line_number;
	}
	return (map);
}





//int				ft_check_lines_number(int fd)
//{
//	char	*line;
//	int		number_of_lines;
//
//	number_of_lines = 0;
//	while (get_next_line(fd, &line) == 1)
//		number_of_lines++;
//	return (number_of_lines);
//}
//
//int				ft_ft_check_columns_number(int fd)
//{
//	char	*line;
//	int		number_of_columns;
//	char	**columns;
//
//	number_of_columns = 0;
//	get_next_line(fd, &line);
//	columns = ft_strsplit(line, ' ');
//	while (columns[number_of_columns])
//		number_of_columns++;
//	return (number_of_columns);
//}
//
//t_coordinates	**ft_create_map(int lines_nbr, int columns_nbr)
//{
//	t_coordinates	**arr_of_coordinates;
//	int				i;
//
//	i = 0;
//	arr_of_coordinates = (t_coordinates **)malloc(sizeof(t_coordinates *) *
//	lines_nbr);
//	while (i < lines_nbr)
//	{
//		arr_of_coordinates[i] = (t_coordinates *)malloc(sizeof(t_coordinates) *
//		columns_nbr);
//		i++;
//	}
//	return (arr_of_coordinates);
//}
//
//void			ft_add_coordinates_to_arr(char **coordinates, int x,
// int y, t_map_mlx map)
//{
//	while (coordinates[x])
//	{
//		map.arr_of_coordinates[x][y].x = x;
//		map.arr_of_coordinates[x][y].y = y;
//		map.arr_of_coordinates[x][y].z = ft_atoi(coordinates[x]);
//		x++;
//	}
//}
//
//int				ft_read_map(int fd, t_map_mlx map_mlx)
//{
//	char	*line;
//	char	**coordinates;
//	int		x;
//	int		y;
//
//	y = 0;
//	while (get_next_line(fd, &line) == 1)
//	{
//		x = 0;
//		coordinates = ft_strsplit(line, ' ');
//		ft_add_coordinates_to_arr(coordinates, x, y, map_mlx);
//		free(line);
//		ft_free_after_split(coordinates);
//		y++;
//	}
//	return (1);
//}
