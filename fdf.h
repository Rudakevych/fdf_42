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

# define BUFF_SIZE 100
# define READING_FAIL -1
# define I_AM_READING 1
# define READING_FINISHED 0
# define LENGTH 700
# define WIDTH 500

typedef struct		s_coordinates
{
	int 			x;
	int 			y;
	int 			z;
	char 			*color;
} 					t_coordinates;

typedef struct		s_map
{
	int 			columns_nbr;
	int 			lines_nbr;
	t_coordinates	**map_data;
} 					t_map;

typedef struct		s_vector
{
	int 			x;
	int 			y;
	int 			color;
}					t_vector;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char 			*img_data_addr;
	unsigned int	img_color_value;
}					t_window;

typedef struct		s_dx_dy_sx_sy
{
	int 			dx;
	int 			dy;
	int 			sx;
	int 			sy;
	int				i;
}					t_d_s_points;

int					ft_read_map(int fd, t_coordinates **arr_of_coordinates, int lines_nbr, int columns_nbr);
int					get_next_line(const int fd, char **line);
int					ft_check_lines_number(int fd);
int					ft_ft_check_columns_number(int fd);
t_coordinates		**ft_create_map(int lines_nbr, int columns_nbr);
void				ft_free_after_split(char **arr);
void				draw_line(t_vector start, t_vector end, t_window window);
void				draw_net(t_map map, t_window window, t_coordinates	**arr_of_coordinates);


#endif
