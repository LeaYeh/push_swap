/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:31:21 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 16:51:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	safe_free(void **buf)
{
	free(*buf);
	*buf = NULL;
}

void	free_array(void **arr, int count)
{
	int	i;

	if (arr == NULL || count == 0)
		return ;
	if (count == -1)
		count = get_array_len(arr);
	i = 0;
	while (i < count)
	{
		if (arr[i])
			safe_free((void **)&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}
