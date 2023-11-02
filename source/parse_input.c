/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:35:38 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 18:58:32 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	_parse_number(int **nbr_array, char **arr, int len)
{
	int	i;

	*nbr_array = (int *)malloc(sizeof(int) * len);
	if (!*nbr_array)
		return (-1);
	if (!check_all_number(arr))
	{
		free(*nbr_array);
		return (-1);
	}
	i = 0;
	while (arr[i])
	{
		if (ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
		{
			free(*nbr_array);
			return (-1);
		}
		(*nbr_array)[i] = ft_atol(arr[i]);
		i++;
	}
	return (i);
}

char	**_parse_str(char *str)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	if (!tmp)
		return (NULL);
	if (!check_all_number(tmp) || get_array_len((void **)tmp) == 0)
	{
		free_array((void **)tmp, -1);
		return (NULL);
	}
	return (tmp);
}

static int	_parse_number_from_str(int **nbr_array, char *str)
{
	int		i;
	char	**tmp;

	tmp = _parse_str(str);
	if (!tmp)
		return (-1);
	*nbr_array = (int *)malloc(sizeof(int) * (get_array_len((void **)tmp)));
	if (!nbr_array)
	{
		free_array((void **)tmp, -1);
		return (-1);
	}
	i = -1;
	while (tmp[++i])
	{
		if (ft_atol(tmp[i]) > INT_MAX || ft_atol(tmp[i]) < INT_MIN)
		{
			free_array((void **)tmp, -1);
			free(*nbr_array);
			return (-1);
		}
		(*nbr_array)[i] = ft_atol(tmp[i]);
	}
	free_array((void **)tmp, -1);
	return (i);
}

int	parse_input_number(int **nbr_array, int argc, char **argv)
{
	int		count;
	char	*read_input;

	if (argc == 1)
	{
		read_input = get_next_line(STDIN_FILENO);
		remove_last_newline(&read_input);
		count = _parse_number_from_str(nbr_array, read_input);
		free(read_input);
		close(STDIN_FILENO);
		read_input = get_next_line(STDIN_FILENO);
		free(read_input);
	}
	else if (argc > 2)
		count = _parse_number(nbr_array, argv + 1, argc - 1);
	else
		count = _parse_number_from_str(nbr_array, argv[1]);
	if (count > 0 && !check_dup_number(*nbr_array, count))
	{
		free(*nbr_array);
		count = -1;
	}
	return (count);
}
