/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:26 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 16:48:22 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_tab	*init_ps_tab(int *nbr_array, int size)
{
	t_ps_tab	*tab;

	tab = (t_ps_tab *)malloc(sizeof(t_ps_tab));
	if (!tab)
		return (NULL);
	tab->stack_a = init_stack(nbr_array, size);
	if (!tab->stack_a)
	{
		free(tab);
		return (NULL);
	}
	tab->stack_b = NULL;
	return (tab);
}

t_list	*init_stack(int *nbr_array, int size)
{
	t_list	*head;
	t_list	*node;
	int		*num;

	head = NULL;
	while (size-- > 0)
	{
		num = copy_nbr(nbr_array, size);
		if (!num)
		{
			ft_lstclear(&head, free);
			break ;
		}
		node = ft_lstnew(num);
		if (!node)
		{
			ft_lstclear(&head, free);
			break ;
		}
		ft_lstadd_front(&head, node);
	}
	free(nbr_array);
	return (head);
}

void	destroy_ps_table(t_ps_tab **tab)
{
	ft_lstclear(&((*tab)->stack_a), free);
	ft_lstclear(&((*tab)->stack_b), free);
	free(*tab);
	tab = NULL;
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
