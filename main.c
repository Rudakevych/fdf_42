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


//int		fd_open_file_with_map()
//{
//	int fd;
//
//	//	fd = open(argv[1], O_RDONLY);
//	fd = open("/Users/yrudakev/CLionProjects/FdF_worked_version/test_maps/42.fdf", O_RDONLY);
////	fd = open("/Users/yrudakev/CLionProjects/FdF_worked_version/test_maps/elem-col.fdf", O_RDONLY);
////	fd = open("/Users/yrudakev/CLionProjects/FdF_worked_version/test_maps/basictest.fdf", O_RDONLY);
//	if (fd < 0)
//	{
//		ft_putstr("error\n");
//		return (0);
//	}
//	return (fd);
//}


void	ft_display_controls()
{
	ft_putstr(" \n____________________________\nCONTROLS:\nTranslation:\n	Y: Key: UP, DOWN\n	X: Key: LEFT, RIGHT\n\nRotation:\n	X: Keypad: 1, 4\n	Y: Keypad: 2, 5\n	Z: Keypad: 3, 6\n\\nZoom:\n	IN: Keypad: +\n	OUT: Keypad: -\n____________________________\n");
}

int		main(int argc, char **argv)
{
	int				fd;
//	t_map_mlx		map;
	t_map			*map;
	t_env			*env;

	fd = 0;
	if (argc == 2)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			ft_error_malloc();
//		fd = fd_open_file_with_map(); // fd = 0;
		map = ft_read_map(fd, argv);
		if (map->lenght == 0 || map->lines[0]->len == 0)
			ft_error_map();
		env->map = map;
		ft_center_of_map(env);
		ft_display_controls();
		ft_init_new_window(env, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
		ft_map_adaptation(env);
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_hook(env->win, 2, 3, key_hook, env);
		mlx_loop(env->mlx);





//		map.lines_nbr = ft_check_lines_number(fd) + 1;
//		map.columns_nbr = ft_ft_check_columns_number(fd) + 1;
//
//		printf("lines:   %d, columns   %d\n", map.lines_nbr - 1, map.columns_nbr - 1); // MAP SIZE test - OK
//		close(fd);
//
//		map.arr_of_coordinates = ft_create_map(map.lines_nbr, map.columns_nbr);
//		fd = fd_open_file_with_map();
//		if (!(ft_read_map(fd, map))) {
//			ft_putstr("error\n");
//			return (0);
//		}
//		map.mlx_ptr = mlx_init();
//		map.win_ptr = mlx_new_window(map.mlx_ptr, LENGTH, WIDTH, "fdf");
//		//	draw_net(map);
//		draw_net_3d(map);
//
//		mlx_loop(map.mlx_ptr);
//		//	close(fd);
//		// add code for free arr_of_coordinates
//		//	system("leaks -q main");
	}
	else
		ft_putstr("ERROR: Usage -> ./fdf <filename>");
	return 0;
}



















/** test */
//	t_vector start;
//	t_vector end;
//	start.x = 20;
//	start.y = 20;
//	start.color = 0xFFFFFF;
//	end.x = 100;
//	end.y = 100;
//	end.color = 0xFFFFFF;
//	ft_draw_line(start, end, window);



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
//	ft_draw_line(start, end, window);
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
