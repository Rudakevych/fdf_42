/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:31:49 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/27 14:34:36 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*node;

	size = 0;
	node = begin_list;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}
