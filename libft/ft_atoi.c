/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:45:29 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/01 14:45:35 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_is_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r')
		return (0);
	return (1);
}

static int	ft_is_double_walues(const char *str)
{
	if ((*str == '+' || *str == '-') &&
		(*(str + 1) == '+' || *(str + 1) == '-'))
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int					is_minus;
	unsigned long int	result;

	is_minus = 1;
	result = 0;
	while (!ft_is_spaces(*str))
		str++;
	if (!ft_is_double_walues(str))
		return (0);
	if (*str == '-')
		is_minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > 9223372036854775807 && is_minus == -1)
			return (0);
		if (result >= 9223372036854775807 && is_minus == 1)
			return (-1);
		str++;
	}
	return ((int)result * is_minus);
}
