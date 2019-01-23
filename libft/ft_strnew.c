/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:22:36 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/05 14:22:45 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
