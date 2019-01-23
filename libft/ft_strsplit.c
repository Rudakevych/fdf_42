/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:10:41 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/07 16:25:30 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_word_count(char const *str, char delim)
{
	size_t		i;
	size_t		word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		if (str[i] != '\0')
			word_count++;
		while (str[i] != delim && str[i] != '\0')
			i++;
	}
	return (word_count);
}

static size_t	ft_word_size(char const *s, size_t count, char delim)
{
	size_t	word_size;
	size_t	i;

	word_size = 0;
	i = count;
	while (s[i] != '\0' && s[i] != delim)
	{
		word_size++;
		i++;
	}
	return (word_size);
}

static char		*ft_make_word(char const *s, size_t count, size_t word_size)
{
	size_t	i;
	size_t	j;
	char	*word;

	j = 0;
	i = count;
	if (!(word = (char *)malloc(sizeof(char) * (word_size + 1))))
		return (NULL);
	while (word_size > 0)
	{
		word[j] = s[i];
		word_size--;
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	word_len;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (!s || !(arr = (char **)malloc(sizeof(char *) *
			(ft_word_count(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		word_len = ft_word_size(s, i, c);
		if (word_len != 0)
			arr[j++] = ft_make_word(s, i, word_len);
		i = i + word_len;
	}
	arr[j] = NULL;
	return (arr);
}
