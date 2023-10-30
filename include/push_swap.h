/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 00:29:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_ps_tab
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_ps_tab;


int			parse_input_number(int **nbr_array, int argc, char **argv);

int			get_array_len(char **arr);

void		exit_error(void);

t_ps_tab	*init_ps_tab(int *nbr_array, int size);
t_list		*init_stack(int *nbr_array, int size);
// void		destroy_stack(t_list *a, t_list *b);
void		print_stack(t_list *s);

bool		swap_first2(t_list **s);
void		sa(t_ps_tab **tab);
void		sb(t_ps_tab **tab);
void		pa(t_ps_tab **tab);
void		pb(t_ps_tab **tab);
void		ra(t_ps_tab **tab);
void		rra(t_ps_tab **tab);

#endif