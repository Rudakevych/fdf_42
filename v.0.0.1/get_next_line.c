/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrudakev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:40:59 by yrudakev          #+#    #+#             */
/*   Updated: 2018/11/28 13:41:16 by yrudakev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*ft_create_node(int fd)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	node->content = ft_strnew(0);
	node->content_size = (size_t)fd;
	node->next = NULL;
	return (node);
}

static t_list	*ft_create_head_if_no_heads(t_list **static_list, int fd)
{
	t_list	*first_node;

	if ((*static_list) == NULL)
	{
		(*static_list) = ft_create_node(fd);
		return (*static_list);
	}
	first_node = *static_list;
	while (first_node)
	{
		if (first_node->content_size == (size_t)fd)
			return (first_node);
		first_node = first_node->next;
	}
	first_node = ft_create_node(fd);
	first_node->next = (*static_list);
	(*static_list) = first_node;
	return ((*static_list));
}

static int		ft_read_from_file(t_list **static_list)
{
	int		rnum;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp_static_content;

	if ((*static_list)->content == NULL)
		return (READING_FINISHED);
	while ((rnum = read((*static_list)->content_size, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rnum] = '\0';
		tmp_static_content = ft_strjoin((*static_list)->content, buffer);
		free((*static_list)->content);
		(*static_list)->content = tmp_static_content;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ft_strlen((*static_list)->content) == 0)
		return (READING_FINISHED);
	if (rnum < 0)
		return (READING_FAIL);
	return (I_AM_READING);
}

static void		ft_write(int n_num, t_list *p_list, char **line, char *tmp)
{
	(*line) = ft_strsub(p_list->content, 0, (size_t)n_num);
	tmp = ft_strsub(p_list->content, n_num + 1,
					ft_strlen(p_list->content) - n_num);
	free(p_list->content);
	p_list->content = tmp;
}

int				get_next_line(const int fd, char **line)
{
	char			*tmp;
	static t_list	*static_list = NULL;
	t_list			*p_list;
	int				n_num;
	char			*p_n_num;

	tmp = NULL;
	if (BUFF_SIZE < 1 || fd < 0 || read(fd, NULL, 0))
		return (READING_FAIL);
	p_list = ft_create_head_if_no_heads(&static_list, fd);
	if (ft_read_from_file(&p_list) <= 0)
		return (0);
	if ((p_n_num = ft_strchr(p_list->content, '\n')))
	{
		n_num = p_n_num - (char *)p_list->content;
		ft_write(n_num, p_list, line, tmp);
	}
	else
	{
		(*line) = ft_strdup(p_list->content);
		free(p_list->content);
		p_list->content = NULL;
	}
	return (I_AM_READING);
}
