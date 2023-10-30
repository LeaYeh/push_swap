/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 16:39:45 by lyeh             ###   ########.fr       */
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

int			get_array_len(void **arr);
int			*copy_nbr(int *nbr_array, int idx);

void		safe_free(void **buf);
void		free_array(void **arr, int count);

void		exit_error(void);
bool		valid_number(char *str);
bool		check_dup_number(int *arr, int size);
bool		check_all_number(char **arr);

t_ps_tab	*init_ps_tab(int *nbr_array, int size);
t_list		*init_stack(int *nbr_array, int size);
void		destroy_ps_table(t_ps_tab **tab);
void		print_stack(t_list *s);

bool		swap_first2(t_list **s);
void		sa(t_ps_tab **tab);
void		sb(t_ps_tab **tab);
void		pa(t_ps_tab **tab);
void		pb(t_ps_tab **tab);
void		ra(t_ps_tab **tab);
void		rb(t_ps_tab **tab);
void		rr(t_ps_tab **tab);
void		rra(t_ps_tab **tab);
void		rrb(t_ps_tab **tab);
void		rrr(t_ps_tab **tab);

bool		is_sorted(t_list *s);

#endif