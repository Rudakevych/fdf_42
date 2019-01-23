/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:36:30 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/02 18:36:42 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	let;
	unsigned char	*new_s;
	size_t			i;

	let = (unsigned char)c;
	new_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == let)
			return ((void *)(new_s + i));
		i++;
	}
	return (NULL);
}
