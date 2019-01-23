/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:00:34 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/22 15:01:16 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_sqrt(int nb)
{
	int	num;

	num = nb;
	while ((num - nb / num) > 0)
		num = (num + nb / num) / 2;
	if (nb % num != 0)
		return (0);
	return (num);
}
