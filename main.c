/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:54:01 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/17 14:54:13 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *
	cc main.c -lmlx -framework OpenGL -framework AppKit     =>>>  compiling

	cat /usr/share/man/man3/[mlx function] =>>> before open MAN

	man /usr/share/man/man3/mlx.1

 	man 3 math
 */

/**
 * Reminder:
 *  Validate map!!!!
 */

int		fd_open_file_with_map()
{
	int fd;

	//	fd = open(argv[1], O_RDONLY);
//	fd = open("/Users/yrudakev/CLionProjects/FdF_worked_version/additional_files/test_maps/42.fdf", O_RDONLY);
	fd = open("/Users/yrudakev/CLionProjects/FdF_worked_version/elem-col.fdf", O_RDONLY);
	if (fd < 0) {
		ft_putstr("error\n");
		return (0);
	}
	return (fd);
}

//t_window	*init_new_window()
//{
//	t_window	*window;
//
//	// init and create new window
//	window->mlx_ptr = mlx_init();
//	window->win_ptr = mlx_new_window(window.mlx_ptr, LENGTH, WIDTH, "fdf");
//
//	// create img
////	if ((window->img_ptr = mlx_new_image(window->mlx_ptr, LENGTH, WIDTH)) == NULL)
////		return (NULL);
////	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img_ptr, LENGTH, WIDTH);
//
//	// takes a standard RGB color parameter, and returns an unsigned int value
////	window.img_color_value = mlx_get_color_value (window.mlx_ptr, 0xFFFFFF);
//
//	//  returns information about the created image, allowing a user to modify it later
//	/** ??????? */
////	window.img_data_addr = mlx_get_data_addr(window.img_ptr, window.img_color_value, 8, 0);
//	return (NULL);
//}

int		main(/*int argc, char **argv*/)
{
	int				fd;
	t_coordinates	**arr_of_coordinates;
	t_map			map;
	t_window		window;

//	if (argc != 2) // ??????
//		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
//	window = NULL;
	fd = fd_open_file_with_map();
	map.lines_nbr = ft_check_lines_number(fd);
	map.columns_nbr = ft_ft_check_columns_number(fd);
	close(fd);

	arr_of_coordinates = ft_create_map(map.lines_nbr, map.columns_nbr);
	fd = fd_open_file_with_map();
	if (!(ft_read_map(fd, arr_of_coordinates)))
	{
		ft_putstr("error\n");
		return (0);
	}
	// init new window
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, LENGTH, WIDTH, "fdf");
	draw_net(map, window, arr_of_coordinates);
	mlx_loop(window.mlx_ptr);

	/** test */
//	t_vector start;
//	t_vector end;
//	start.x = 20;
//	start.y = 20;
//	start.color = 0xFFFFFF;
//	end.x = 100;
//	end.y = 100;
//	end.color = 0xFFFFFF;
//	draw_line(start, end, window);




//	mlx_loop(window.mlx_ptr);
	close(fd);
	// add code for free arr_of_coordinates
//	system("leaks -q main");
	return 0;
}























//// draw vertical line
//void 	draw_vertical_line(void *mlx_ptr, void *win_ptr, int x, int y, int color)
//{
//	// how to use x here ?
//	while (y < 100)
//	{
//		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//		y++;
//	}
//}
//
//// draw horizontal line
//void 	draw_horizontal_line(void *mlx_ptr, void *win_ptr, int x, int y, int color)
//{
//	// how to use y here ?
//	while (x < 100)
//	{
//		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//		x++;
//	}
//}
//
///**
// * Переписати нормально для всіх випадків лінії !!!!!!!!!!!!!!!!!!!!!!!!!!
// */
// // draw line used Bresenham's line algorithm
//void	draw_oblique_line(int x0, int y0, int x1, int y1, int color, void *mlx_ptr, void *win_ptr)
//{
//	int dx = abs(x1 - x0);
//	int dy = abs(y1 - y0);
//	int sx = x1 >= x0 ? 1 : -1;
//	int sy = y1 >= y0 ? 1 : -1;
//
//	if (dy <= dx)
//	{
//		int d = (dy << 1) - dx;
//		int d1 = dy << 1;
//		int d2 = (dy - dx) << 1;
//		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
//		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
//		{
//			if ( d >0)
//			{
//				d += d2;
//				y += sy;
//			}
//			else
//				d += d1;
//			mlx_pixel_put(mlx_ptr, win_ptr,x, y, color);
//		}
//	}
//	else
//	{
//		int d = (dx << 1) - dy;
//		int d1 = dx << 1;
//		int d2 = (dx - dy) << 1;
//		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
//		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
//		{
//			if ( d >0)
//			{
//				d += d2;
//				x += sx;
//			}
//			else
//				d += d1;
//			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//		}
//	}
//
//}
//
//int		main2(int argc, char **argv)
//{
//	void	*mlx_ptr;
//	void	*win_ptr;
//	void	*img_ptr;
//
//	mlx_ptr = mlx_init(); // creating connection to the window
////	* open new window
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf window");
//
////	* draw one white dot
//	mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF);
////	* draw second white dot
//	mlx_pixel_put(mlx_ptr, win_ptr, 220, 220, 0xFFFFFF);
////	* draw text
//	mlx_string_put(mlx_ptr, win_ptr, 20, 20, 0xFFFFFF,"Hi dude");
//	int x = 0;
//	int y = 50;
////	* draw vertical line
//	draw_vertical_line(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
////	* draw horizontal line
//	draw_horizontal_line(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
////	* draw oblique used Bresenham's line algorithm
//	int x0 = 50;
//	int y0 = 50;
//	int x1 = 130;
//	int y1 = 130;
//
//	t_window window;
//	t_vector start;
//	t_vector end;
//
//	start.x = 20;
//	start.y = 20;
//	start.color = 0xFFFFFF;
//	end.x = 100;
//	end.y = 100;
//	end.color = 0xFFFFFF;
//	window.mlx_ptr = mlx_init();
//	window.win_ptr = mlx_new_window(window.mlx_ptr, 500, 500, "fdf window");
//	draw_line(start, end, window);
//	mlx_loop(window.mlx_ptr);
//
//
//
//
//	draw_oblique_line(x0, y0, x1, y1, 0xff0000, mlx_ptr, win_ptr);
//
//
//
//
////	* handle keyboard or mouse event
//	mlx_loop(mlx_ptr);
//
//
////	* working with images
//	// create a new image in memory with width and height 200
//	img_ptr = mlx_new_image(mlx_ptr, 200, 200);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 300, 300);
//}
