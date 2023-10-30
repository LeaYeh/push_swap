/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:45:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 16:04:05 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *s)
{
	bool	ret;

	ret = true;
	if (!s || !s->next)
		return (ret);
	while (s->next)
	{
		if (*((int *)s->content) > *((int *)s->next->content))
		{
			ret = false;
			break ;
		}
		s = s->next;
	}
	return (ret);
}

