/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:39 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 18:44:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_ps_tab **tab)
{
	int		min_index;
	t_list	*min_node;

	while ((*tab)->stack_a)
	{
		min_index = get_min_index((*tab)->stack_a);
		min_node = get_min_node((*tab)->stack_a);
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
