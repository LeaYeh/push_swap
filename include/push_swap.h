/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/01 18:07:07 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "ft_dprintf.h"
# include "get_next_line.h"

typedef struct s_ps_tab
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		move_cnt;
}	t_ps_tab;


int			parse_input_number(int **nbr_array, int argc, char **argv);

int			get_array_len(void **arr);
int			*copy_nbr(int *nbr_array, int idx);
bool		is_sign(char c);

void		safe_free(void **buf);
void		free_array(void **arr, int count);

void		exit_error(void);
bool		valid_number(char *str);
bool		check_dup_number(int *arr, int size);
bool		check_all_number(char **arr);
bool		check_limit(long *arr, int size);

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
t_list		*get_min_node(t_list *s);
t_list		*get_max_node(t_list *s);
int			find_node_index(t_list *s, t_list *node);

bool		sort(t_ps_tab **tab);
void		insert_sort(t_ps_tab **tab, char *type);
void		three_sort(t_ps_tab **tab);
void		promote_node_from_a(t_ps_tab **tab, char *type);

#endif