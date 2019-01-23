/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:20:32 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/05 13:22:08 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_point;

	if (size <= 0)
		return (NULL);
	if (!(mem_point = malloc(size)))
		return (NULL);
	ft_memset(mem_point, 0, size);
	return (mem_point);
}
