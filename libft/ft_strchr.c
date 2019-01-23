/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:02:33 by yrudakev          #+#    #+#             */
/*   Updated: 2018/10/31 14:02:41 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	let;
	char			*new_str;

	let = (unsigned char)c;
	new_str = (char *)s;
	while (*s != '\0')
	{
		if (*s == let)
			return (new_str);
		s++;
		new_str++;
	}
	if (let == '\0')
		return (new_str);
	return (NULL);
}
