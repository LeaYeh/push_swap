/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:45:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/01 17:42:52 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *s)
{
	bool	ret;

	ret = true;
	if (!s || !s->next)
		return (ret);
	while (s->next)
	{
		if (*((int *)s->content) > *((int *)s->next->content))
		{
			ret = false;
			break ;
		}
		s = s->next;
	}
	return (ret);
}

t_list	*get_max_node(t_list *s)
{
	t_list	*max_node;

	if (!s)
		return (NULL);
	max_node = s;
	while (s)
	{
		if (*((int *)(max_node->content)) < *((int *)(s->content)))
			max_node = s;
		s = s->next;
	}
	return (max_node);
}

t_list	*get_min_node(t_list *s)
{
	t_list	*min_node;

	if (!s)
		return (NULL);
	min_node = s;
	while (s)
	{
		if (*((int *)(min_node->content)) > *((int *)(s->content)))
			min_node = s;
		s = s->next;
	}
	return (min_node);
}

int	find_node_index(t_list *s, t_list *node)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s)
	{
		if (*((int *)(node->content)) == *((int *)(s->content)))
			return (i);
		s = s->next;
		i++;
	}
	return (-1);
}
