/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:38:26 by yrudakev          #+#    #+#             */
/*   Updated: 2018/10/30 15:38:33 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = ft_strlen(dst);
	j = 0;
	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while ((src[j] != '\0') && (dst_len + j < dstsize - 1))
	{
		dst[j + i] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst_len + src_len);
}
