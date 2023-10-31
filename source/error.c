#include "push_swap.h"

void	exit_error()
{
	ft_dprintf(2, "Error\n");
	exit(-1);
}

bool	valid_number(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || \
			(ft_strlen(str) > 1 && i == 0 && is_sign(str[i])))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_dup_number(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && arr[i] == arr[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_all_number(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!valid_number(arr[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_limit(long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}