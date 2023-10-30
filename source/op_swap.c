/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:12:49 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 18:59:55 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap_first2(t_list **s)
{
	t_list	*tmp_node;

	if (!*s || !(*s)->next)
		return (false);
	tmp_node = *s;
	*s = ft_lstlast(*s);
	(*s)->next = tmp_node;
	*s = tmp_node->next;
	tmp_node->next = NULL;
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
