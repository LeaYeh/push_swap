/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:16:16 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/01 18:50:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	medium_sort(t_ps_tab **tab)
{
	while (ft_lstsize((*tab)->stack_a) > 3)
	{
		promote_node_from_a(tab, "min");
		pb(tab);
	}
	three_sort(tab);
	while ((*tab)->stack_b)
		pa(tab);
}
