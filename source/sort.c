/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:39 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 17:01:06 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort(t_ps_tab **tab)
{
	int	size;

	if (is_sorted((*tab)->stack_a))
		return (true);
	size = ft_lstsize((*tab)->stack_a);
	if (size == 2)
		sa(tab);
	else if (size == 3)
		three_sort(tab);
	else if (size > 3 && size < 100)
		insert_sort(tab, "min");
	else
		insert_sort(tab, "min");
	return (is_sorted((*tab)->stack_a));
}

void	insert_sort(t_ps_tab **tab, char *type)
{
	if (is_sorted((*tab)->stack_a))
		return ;
	while (ft_lstsize((*tab)->stack_a) > 3)
	{
		promote_node_from_a(tab, type);
		pb(tab);
	}
	three_sort(tab);
	while ((*tab)->stack_b)
		pa(tab);
}

void	bubble_sort(int **nbr_array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*nbr_array)[i] > (*nbr_array)[j])
			{
				tmp = (*nbr_array)[i];
				(*nbr_array)[i] = (*nbr_array)[j];
				(*nbr_array)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
