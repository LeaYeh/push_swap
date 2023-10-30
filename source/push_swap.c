/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:11 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 16:47:32 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*nbr_array;
	int			size;
	t_ps_tab	*tab;

	size = parse_input_number(&nbr_array, argc, argv);
	if (size == -1)
		exit_error();
	tab = init_ps_tab(nbr_array, size);
	if (!tab)
		return (-1);
	ft_dprintf(1, "sorted: %d\n", is_sorted(tab->stack_a));
	print_stack(tab->stack_a);
	destroy_ps_table(&tab);
}
