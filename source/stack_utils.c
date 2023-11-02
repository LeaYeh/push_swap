/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:45 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 17:26:53 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sorted_index(int *sorted_array, int target_value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_array[i] == target_value)
			return (i);
		i++;
	}
	return (-1);
}

void	print_stack(t_list *s)
{
	int	i;

	i = 0;
	while (s)
	{
		ft_dprintf(1, "%d: index=%d, value=%d\n", i,
			((t_node *)(s->content))->sorted_index,
			((t_node *)(s->content))->value);
		s = s->next;
		i++;
	}
}
