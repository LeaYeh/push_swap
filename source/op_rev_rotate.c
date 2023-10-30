/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:16:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 18:58:40 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rev_rotate(t_list **s)
{
	t_list	*tmp;
	t_list	*tail;

	if (!*s || !(*s)->next)
		return (false);
	tmp = *s;
	while (tmp->next->next)
		tmp = tmp->next;
	tail = tmp->next;
	tmp->next = NULL;
	tail->next = *s;
	*s = tail;
	return (true);
}

void	rra(t_ps_tab **tab)
{
	if (!rev_rotate(&((*tab)->stack_a)))
		return ;
	ft_dprintf(1, "rra\n");
	(*tab)->move_cnt++;
}

void	rrb(t_ps_tab **tab)
{
	if (!rev_rotate(&((*tab)->stack_b)))
		return ;
	ft_dprintf(1, "rrb\n");
	(*tab)->move_cnt++;
}

void	rrr(t_ps_tab **tab)
{
	if (rev_rotate(&((*tab)->stack_a)) || rev_rotate(&((*tab)->stack_b)))
	{
		ft_dprintf(1, "rrr\n");
		(*tab)->move_cnt++;
	}
}
