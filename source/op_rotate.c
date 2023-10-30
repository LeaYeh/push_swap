/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:37:27 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 18:59:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate(t_list **s)
{
	t_list	*tmp;

	if (!*s || !(*s)->next)
		return (false);
	tmp = *s;
	*s = ft_lstlast(*s);
	(*s)->next = tmp;
	*s = tmp->next;
	tmp->next = NULL;
	return (true);
}

void	ra(t_ps_tab **tab)
{
	if (!rotate(&((*tab)->stack_a)))
		return ;
	rotate(&((*tab)->stack_a));
	ft_dprintf(1, "ra\n");
	(*tab)->move_cnt++;
}

void	rb(t_ps_tab **tab)
{
	if (!rotate(&((*tab)->stack_b)))
		return ;
	ft_dprintf(1, "rb\n");
	(*tab)->move_cnt++;
}

void	rr(t_ps_tab **tab)
{
	if (rotate(&((*tab)->stack_b)) || rotate(&((*tab)->stack_b)))
	{
		ft_dprintf(1, "rr\n");
		(*tab)->move_cnt++;
	}
}
