/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:11:35 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/02 17:11:45 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_new;
	unsigned char		*src_new;
	size_t				i;

	i = 0;
	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	if (src_new < dst_new)
	{
		while ((int)--len >= 0)
			dst_new[len] = src_new[len];
	}
	else
	{
		while (i < len)
		{
			dst_new[i] = src_new[i];
			i++;
		}
	}
	return (dst);
}
