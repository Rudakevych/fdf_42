/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:30:38 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/06 14:30:41 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_check_num_length(int number)
{
	int	ret;

	ret = 0;
	if (number < 0)
		number = -1 * number;
	if (number == 0)
		ret++;
	while (number > 0)
	{
		number = number / 10;
		ret++;
	}
	return (ret);
}

static void		ft_just_reverse_str(char *str, int len)
{
	char	item;
	int		i;
	int		j;

	j = len - 1;
	i = 0;
	while (i < j)
	{
		item = str[i];
		str[i] = str[j];
		str[j] = item;
		j--;
		i++;
	}
}

static int		ft_is_minus_number(int numb)
{
	int ret;

	ret = 1;
	if (numb < 0)
		ret = -1;
	return (ret);
}

static char		*ft_itoa_logic(char *str, int i, int n_len, int n)
{
	int		is_minus;

	is_minus = ft_is_minus_number(n);
	if (is_minus < 0)
		n = n * (-1);
	while (n_len > 0)
	{
		if ((n % 10) > 0)
			str[i++] = (char)(n % 10 + '0');
		else
			str[i++] = '0';
		n = n / 10;
		n_len--;
	}
	if (is_minus < 0)
		str[i++] = '-';
	ft_just_reverse_str(str, i);
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		n_len;

	i = 0;
	n_len = ft_check_num_length(n);
	if (!(str = ft_strnew((size_t)n_len + 1)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_itoa_logic(str, i, n_len, n);
	return (str);
}
