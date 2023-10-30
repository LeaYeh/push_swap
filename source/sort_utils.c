/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:45:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 18:13:29 by lyeh             ###   ########.fr       */
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

int	get_min_index(t_list *s)
{
	int		i;
	t_list	*min_node;

	if (!s)
		return (-1);
	min_node = get_min_node(s);
	i = 0;
	while (s)
	{
		if (*((int *)(min_node->content)) == *((int *)(s->content)))
			return (i);
		s = s->next;
		i++;
	}
	return (-1);
}
