/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:39 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/31 17:13:32 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_ps_tab **tab)
{
	int		min_index;

	if (is_sorted((*tab)->stack_a))
		return ;
	while ((*tab)->stack_a)
	{
		min_index = find_node_index((*tab)->stack_a,
				get_min_node((*tab)->stack_a));
		if (min_index < ft_lstsize((*tab)->stack_a) / 2)
		{
			while (min_index--)
				ra(tab);
		}
		else
		{
			while ((ft_lstsize((*tab)->stack_a) - min_index++))
				rra(tab);
		}
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
	if (min_index == 0)
		return (sa(tab), ra(tab));
}
