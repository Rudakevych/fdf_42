/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:10:16 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/02 16:10:22 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_new;
	char	*src_new;

	i = 0;
	dst_new = (char *)dst;
	src_new = (char *)src;
	while (n > i)
	{
		dst_new[i] = src_new[i];
		i++;
	}
	return (dst);
}
