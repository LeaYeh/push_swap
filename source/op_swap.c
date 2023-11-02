/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:12:49 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/01 19:34:38 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap_first2(t_list **s)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!*s || !(*s)->next)
		return (false);
	first_node = *s;
	second_node = (*s)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*s = second_node;
	return (true);
}

void	sa(t_ps_tab **tab)
{
	if (swap_first2(&((*tab)->stack_a)))
	{
		ft_dprintf(1, "sa\n");
		(*tab)->move_cnt++;
	}
}

void	sb(t_ps_tab **tab)
{
	if (swap_first2(&((*tab)->stack_b)))
	{
		ft_dprintf(1, "sb\n");
		(*tab)->move_cnt++;
	}
}

void	ss(t_ps_tab **tab)
{
	if (swap_first2(&((*tab)->stack_a)) || swap_first2(&((*tab)->stack_b)))
	{
		ft_dprintf(1, "ss\n");
		(*tab)->move_cnt++;
	}
}
