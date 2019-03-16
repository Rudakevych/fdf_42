/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:31:44 by yrudakev          #+#    #+#             */
/*   Updated: 2019/03/16 14:31:47 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_malloc()
{
	ft_putstr("ERROR: Can't allocate memory by malloc!!!!\n");
	ft_exit();
}

void	ft_exit()
{
	exit(1);
}

void	ft_error_fd()
{
	ft_putstr("ERROR: fd >= 0");
	ft_exit();
}

void	ft_error_map()
{
	ft_putstr("ERROR: Map is incorrect.");
	ft_exit();
}