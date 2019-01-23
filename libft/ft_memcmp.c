/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:37:12 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/02 18:37:17 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_new;
	unsigned char	*s2_new;
	size_t			i;

	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_new[i] != s2_new[i])
			return (s1_new[i] - s2_new[i]);
		i++;
	}
	return (0);
}
