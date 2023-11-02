/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:45:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 18:11:53 by lyeh             ###   ########.fr       */
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
		if (((t_node *)(s->content))->value > \
			((t_node *)(s->next->content))->value)
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
		if (((t_node *)(max_node->content))->value < \
			((t_node *)(s->content))->value)
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
		if (((t_node *)(min_node->content))->value > \
			((t_node *)(s->content))->value)
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
		if (((t_node *)(node->content))->value == \
			((t_node *)(s->content))->value)
			return (i);
		s = s->next;
		i++;
	}
	return (-1);
}

void	promote_node_from_a(t_ps_tab **tab, char *type)
{
	int		index;
	t_list	*node;

	if (ft_strncmp(type, "min", 3) == 0)
		node = get_min_node((*tab)->stack_a);
	else
		node = get_max_node((*tab)->stack_a);
	index = find_node_index((*tab)->stack_a, node);
	if (index < ft_lstsize((*tab)->stack_a) / 2)
	{
		while (index--)
			ra(tab);
	}
	else
	{
		while ((ft_lstsize((*tab)->stack_a) - index++))
			rra(tab);
	}
}
