/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:43:39 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/27 14:51:09 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*last;
	t_list	*here;
	t_list	*next;

	last = NULL;
	here = *begin_list;
	next = NULL;
	while (here != NULL)
	{
		next = here->next;
		here->next = last;
		last = here;
		here = next;
	}
	*begin_list = last;
}
