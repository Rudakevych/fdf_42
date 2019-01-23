/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:57:45 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/12 15:57:48 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_next;
	t_list	*lst_cur;

	lst_cur = *alst;
	if (!*alst || !del)
		return ;
	while (lst_cur != NULL)
	{
		tmp_next = lst_cur->next;
		del(lst_cur->content, lst_cur->content_size);
		free(lst_cur);
		lst_cur = tmp_next;
	}
	*alst = NULL;
}
