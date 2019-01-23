/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:09:34 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/06 12:09:39 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str_if_zero;
	size_t	first;
	size_t	last;

	if (!s)
		return (NULL);
	first = 0;
	last = ft_strlen(s);
	while (s[first] != '\0' && (s[first] == ' ' || s[first] == '\t' ||
			s[first] == '\n'))
		first++;
	if (s[first] == '\0')
	{
		if (!(str_if_zero = (char *)malloc(1)))
			return (NULL);
		str_if_zero[0] = '\0';
		return (str_if_zero);
	}
	while ((s[last - 1] == ' ' || s[last - 1] == '\t' ||
			s[last - 1] == '\n') && last != 0)
		last--;
	return (ft_strsub(s, (unsigned int)first, last - first));
}
