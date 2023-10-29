/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:26 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/29 21:03:17 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(int *nbr_array, int size)
{
	int		i;
	t_list	*head;
	t_list	*node;

	head = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(&nbr_array[i]);
		if (!node)
			ft_lstclear(&head, free);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

void	destroy_stack(t_list *a, t_list *b)
{
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

void	print_stack(t_list *s)
{
	int	i;

	i = 0;
	while (s)
	{
		ft_dprintf(1, "%d: %d\n", i, *((int *)(s->content)));
		s = s->next;
		i++;
	}
}
