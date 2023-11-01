/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:39 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/01 18:12:19 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort(t_ps_tab **tab)
{
	int	size;

	if (is_sorted((*tab)->stack_a))
		return (true);
	size = ft_lstsize((*tab)->stack_a);
	if (size == 2)
		sa(tab);
	else if (size == 3)
		three_sort(tab);
	else if (size == 4)
	{
		promote_node_from_a(tab, "min");
		pb(tab);
		three_sort(tab);
		pa(tab);
	}
	else if (size == 5)
	{
		promote_node_from_a(tab, "min");
		pb(tab);
		promote_node_from_a(tab, "min");
		pb(tab);
		three_sort(tab);
		pa(tab);
		pa(tab);
	}
	else
		insert_sort(tab, "min");
	return (is_sorted((*tab)->stack_a));
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

void	insert_sort(t_ps_tab **tab, char *type)
{
	if (is_sorted((*tab)->stack_a))
		return ;
	while ((*tab)->stack_a)
	{
		promote_node_from_a(tab, type);
		pb(tab);
	}
	while ((*tab)->stack_b)
		pa(tab);
}

void	three_sort(t_ps_tab **tab)
{
	int		min_index;
	int		max_index;

	if (is_sorted((*tab)->stack_a))
		return ;
	min_index = find_node_index((*tab)->stack_a,
			get_min_node((*tab)->stack_a));
	max_index = find_node_index((*tab)->stack_a,
			get_max_node((*tab)->stack_a));
	if (min_index == 0 && max_index == 1)
	{
		sa(tab);
		ra(tab);
	}
	else if (min_index == 1 && max_index == 2)
		sa(tab);
	else if (min_index == 2 && max_index == 0)
	{
		sa(tab);
		rra(tab);
	}
	else if (min_index == 1 && max_index == 0)
		ra(tab);
	else
		rra(tab);
}
