/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/29 21:02:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

int		parse_input_number(int **nbr_array, int argc, char **argv);

int		get_array_len(char **arr);

void	exit_error(void);

t_list	*init_stack(int *nbr_array, int size);
void	destroy_stack(t_list *a, t_list *b);
void	print_stack(t_list *s);

#endif