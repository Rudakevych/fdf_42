/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:54:26 by yrudakev          #+#    #+#             */
/*   Updated: 2019/01/17 14:54:34 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> //
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include "math.h"
# include <mlx.h>

/**
 * NEW ONE
 */

# define WIDTH 20
# define HEIGHT 20

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 2000

/*
**	Move pixel
*/
# define MOVE_UP -100
# define MOVE_DOWN 100
# define MOVE_LEFT -100
# define MOVE_RIGHT 100

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

# define MOVE_ROT_X_U -M_PI / 64
# define MOVE_ROT_X_D M_PI / 64
# define MOVE_ROT_Y_U -M_PI / 64
# define MOVE_ROT_Y_D M_PI / 64
# define MOVE_ROT_Z_U -M_PI / 64
# define MOVE_ROT_Z_D M_PI / 64

/*
**	Key code
*/
# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78

# define KEY_ROT_X_U 86
# define KEY_ROT_X_D 83
# define KEY_ROT_Y_U 87
# define KEY_ROT_Y_D 84
# define KEY_ROT_Z_U 88
# define KEY_ROT_Z_D 85


typedef struct	s_point {
	double		x;
	double		y;
	double		z;
	double		s;
	int			z_color;
}				t_point;

typedef struct	s_line {
	t_point		**points;
	int			len;
}				t_line;

typedef struct	s_map {
	t_line		**lines;
	int			lenght;
}				t_map;

typedef struct	s_env {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_point		center;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			s_line;
	int			ed;
}				t_env;

typedef struct	s_matrix {
	double		a1;
	double		a2;
	double		a3;
	double		a4;
	double		b1;
	double		b2;
	double		b3;
	double		b4;
	double		c1;
	double		c2;
	double		c3;
	double		c4;
	double		d1;
	double		d2;
	double		d3;
	double		d4;
}				t_matrix;

///*
//**	Parse Map
//**	\file parse_arg.c
//*/
//t_map			*ft_parse_map(char **av, int fd);
//int				ft_point(char *line, int line_number, t_point ***points_arr);
//void			ft_parse_points (char *nb_str);
//int				ft_getnumber(char *str);
//int				ft_map_line(char *map);
//
///*
//**	Draw Map
//**	\file fdf_draw.c
//*/
//void			ft_init_new_window(char *title, int weight, int height, t_env *e);
//void			draw_map(t_env *e);
//
///*
//**	Gestion Error
//**	\file fdf_error.c
//*/
////void			fdf_exit(void);
////void			fdf_malloc_error(void);
//void			fdf_map_error(void);
//void			fdf_arg_error(void);
//
///*
//**	Calcul of matrice
//**	\file fdf_cal_matrice.c
//*/
//
//void			ft_cal_rotation(t_env *e, double rot, char axe);
//void			ft_cal_translat(t_env *e, double x, double y, double z);
//void			ft_cal_scale(t_env *e, double s);
//
///*
//**	Mtarice init
//**	\file fdf_matrice.c
//*/
//t_matrix		*ft_matrice_rotation_x(double beta);
//t_matrix		*ft_matrice_rotation_y(double beta);
//t_matrix		*ft_matrice_rotation_z(double beta);
//t_matrix		*ft_matrice_translation(double tx, double ty, double tz);
//t_matrix		*ft_matrix_scale(double s);
//
///*
//**	Hook
//**	\file fdf_hook.c
//*/
//int				key_hook(int keycode, t_env *e);
//
///*
//**	Function Helpers
//**	\file fdf_helper.c
//*/
//int				get_color(t_point *point1, t_point *point2);
//void			ft_center_of_map(t_env *e);
//void			draw_reload(t_env *e);
//int				point_in_window(t_point point1, t_point point2);
//void			ft_map_adaptation(t_env *e);
//int				point_out_window(t_point *point1);

int				get_next_line(const int fd, char **line);

void			ft_error_malloc();
void			ft_exit();
void			ft_error_fd();
void			ft_error_map();

t_map			*ft_read_map(int fd, char **argv);
int				ft_map_line(char *map);
int				ft_point(char *line, int line_number, t_point ***points_arr);
int				ft_getnumber(char *str);
void			ft_center_of_map(t_env *env);
void			ft_init_new_window(t_env *env, int weight, int height, char *title);
void			ft_map_adaptation(t_env *env);
void			ft_find_translation(double x, double y, double z, t_env *env);
void			ft_find_scale(double size, t_env *env);
t_matrix		*ft_matrice_translation(double tx, double y_point, double z_point);
t_matrix		*ft_matrix_scale(double scale);
static void		ft_matrix_calculation_for_all_points(t_matrix *m, t_env *e);
static void		ft_matrix_calculaton(t_point *p, t_matrix *m, t_env *e);
static void		ft_matrix_calculation_for_all_points(t_matrix *m, t_env *e);
int				expose_hook(t_env *env);
void			draw_reload(t_env *env);
static void		ft_draw_line(t_point point1, t_point point2, t_env *env);
void			ft_draw_map(t_env *env);
int				key_hook(int keycode, t_env *e);





/**
 * OLD ONE
 */

//# define BUFF_SIZE 100
//# define READING_FAIL -1
//# define I_AM_READING 1
//# define READING_FINISHED 0
//# define LENGTH 700
//# define WIDTH 500
//
//typedef struct		s_coordinates
//{
//	int 			x;
//	int 			y;
//	int 			z;
//	int 			color;
//	int 			x_new;
//	int 			y_new;
//	int 			z_new;
//	int 			color_new;
//} 					t_coordinates;
//
//typedef struct		s_map_mlx
//{
//	void			*mlx_ptr;
//	void			*win_ptr;
//	void			*img_ptr;
////	char 			*img_data_addr;
////	unsigned int	img_color_value;
//	int 			columns_nbr;
//	int 			lines_nbr;
//	t_coordinates	**arr_of_coordinates;
//} 					t_map_mlx;
//
//typedef struct		s_dx_dy_sx_sy
//{
//	int 			dx;
//	int 			dy;
//	int 			sx;
//	int 			sy;
//	int				i;
//}					t_d_s_points;
//
//int					get_next_line(const int fd, char **line);
//int					ft_check_lines_number(int fd);
//int					ft_ft_check_columns_number(int fd);
////int					ft_read_map(int fd, t_map_mlx map_mlx);
//void				ft_free_after_split(char **arr);
//t_coordinates		**ft_create_map(int lines_nbr, int columns_nbr);
//void				ft_free_arr_of_coordinates(t_map_mlx *mlx);
//void				ft_draw_line(t_coordinates *start, t_coordinates *end, t_map_mlx mlx);
//void				draw_net(t_map_mlx map);
//void				draw_net_3d(t_map_mlx map);



#endif
