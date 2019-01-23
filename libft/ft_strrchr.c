/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:31:38 by yrudakev          #+#    #+#             */
/*   Updated: 2018/10/31 14:31:45 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		latest_c;
	char	*ret_str;
	char	let;

	i = 0;
	latest_c = 0;
	ret_str = (char *)s;
	let = (char)c;
	while (ret_str[i] != '\0')
	{
		if (ret_str[i] == let)
			latest_c = i;
		i++;
	}
	if (let == '\0')
		return (ret_str + i);
	if (latest_c > 0)
		return (ret_str + latest_c);
	if (ret_str[0] == let)
		return (ret_str);
	else
		return (NULL);
}
