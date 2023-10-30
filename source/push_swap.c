/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:11 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 13:19:25 by lyeh             ###   ########.fr       */
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
	print_stack(tab->stack_a);
	destroy_ps_table(&tab);
}
