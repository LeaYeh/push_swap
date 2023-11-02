/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:26 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 17:48:49 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_tab	*init_ps_tab(int *nbr_array, int size)
{
	t_ps_tab	*tab;
	int			*sorted_array;

	tab = (t_ps_tab *)malloc(sizeof(t_ps_tab));
	if (!tab)
		return (NULL);
	sorted_array = copy_nbr_array(nbr_array, size);
	bubble_sort(&sorted_array, size);
	tab->stack_a = init_stack(nbr_array, sorted_array, size);
	free(nbr_array);
	free(sorted_array);
	if (!tab->stack_a)
	{
		free(tab);
		return (NULL);
	}
	tab->stack_b = NULL;
	tab->move_cnt = 0;
	tab->size = size;
	return (tab);
}

t_list	*init_node(int value, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->sorted_index = index;
	return (ft_lstnew(node));
}

t_list	*init_stack(int *nbr_array, int *sorted_array, int size)
{
	t_list	*head;
	t_list	*node;
	int		*num;
	int		i;

	head = NULL;
	i = size;
	while (i-- > 0)
	{
		num = copy_nbr(nbr_array, i);
		if (!num)
		{
			ft_lstclear(&head, free);
			break ;
		}
		node = init_node(*num, get_sorted_index(sorted_array, *num, size));
		if (!node)
		{
			ft_lstclear(&head, free);
			break ;
		}
		ft_lstadd_front(&head, node);
		free(num);
	}
	return (head);
}

void	destroy_ps_table(t_ps_tab **tab)
{
	ft_lstclear(&((*tab)->stack_a), free);
	ft_lstclear(&((*tab)->stack_b), free);
	free(*tab);
	tab = NULL;
}
