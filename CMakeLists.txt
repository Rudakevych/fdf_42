cmake_minimum_required(VERSION 3.13)
project(FdF_worked_version C)

set(CMAKE_C_STANDARD 99)



add_executable(FdF_worked_version main.c fdf.h map_validation.c read_map.c libft/ft_strcmp.c libft/ft_lstadd.c get_next_line.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strnew.c libft/ft_memcpy.c libft/ft_lstnew.c libft/ft_strjoin.c libft/ft_memset.c libft/ft_memalloc.c libft/ft_strsub.c libft/ft_putstr.c libft/ft_bzero.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_atoi.c libft/ft_strsplit.c free_for_all.c draw_net.c draw_line.c)