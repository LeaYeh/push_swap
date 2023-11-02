/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:21:29 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 18:16:24 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop_top(t_list **s)
{
	t_list	*node;

	node = *s;
	*s = (*s)->next;
	node->next = NULL;
	return (node);
}

void	pa(t_ps_tab **tab)
{
	if (!(*tab)->stack_b)
		return ;
	ft_lstadd_front(&((*tab)->stack_a), pop_top(&((*tab)->stack_b)));
	ft_dprintf(1, "pa\n");
	(*tab)->move_cnt++;
}

void	pb(t_ps_tab **tab)
{
	if (!(*tab)->stack_a)
		return ;
	ft_lstadd_front(&((*tab)->stack_b), pop_top(&((*tab)->stack_a)));
	ft_dprintf(1, "pb\n");
	(*tab)->move_cnt++;
}
