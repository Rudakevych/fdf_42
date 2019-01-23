/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:08:20 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/12 17:08:23 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res_lst;
	t_list	*tmp_lst;

	res_lst = f(lst);
	tmp_lst = res_lst;
	if (!lst || !f)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(tmp_lst->next = f(lst)))
		{
			free(tmp_lst->next);
			return (NULL);
		}
		tmp_lst = tmp_lst->next;
	}
	return (res_lst);
}
