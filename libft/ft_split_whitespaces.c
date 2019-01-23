/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:18:52 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/22 15:18:56 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_split_whitespaces(char *str)
{
	char	*word;
	size_t	length;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	length = ft_strlen(str);
	if (!(word = (char*)malloc(length + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			word[j] = str[i];
			j++;
		}
		i++;
	}
	word[j] = '\0';
	str = word;
	return (str);
}
