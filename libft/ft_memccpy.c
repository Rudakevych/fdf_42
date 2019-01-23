/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:25:47 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/02 16:25:55 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	let;
	unsigned char	*dst_new;
	unsigned char	*src_new;
	size_t			i;

	let = (unsigned char)c;
	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_new[i] = src_new[i];
		if (src_new[i] == let)
			return (dst_new + i + 1);
		i++;
	}
	return (NULL);
}
