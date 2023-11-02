/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:39 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 18:14:11 by lyeh             ###   ########.fr       */
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
	else if (size > 3 && size < 6)
		medium_sort(tab);
	else
		radix_sort(tab);
	return (is_sorted((*tab)->stack_a));
}

int	get_binary_len(int val)
{
	int	i;

	i = 0;
	while (val > 0)
	{
		val /= 2;
		i++;
	}
	return (i);
}

void	radix_sort(t_ps_tab **tab)
{
	int	i;
	int	shift;
	int	tmp;

	shift = 0;
	while (shift < get_binary_len((*tab)->size))
	{
		i = 0;
		while (i < (*tab)->size)
		{
			tmp = ((*((t_node *)(*tab)->stack_a->content)).sorted_index);
			if (((tmp >> shift) & 1) == 0)
				pb(tab);
			else
				ra(tab);
			i++;
		}
		while ((*tab)->stack_b)
			pa(tab);
		shift++;
	}
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
