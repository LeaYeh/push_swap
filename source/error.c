#include "push_swap.h"

void	exit_error()
{
	ft_dprintf(1, "Error\n");
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
		if (!ft_isdigit(str[i]) && !is_sign(str[i]))
			return (false);
		i++;
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
				return (true);
			j++;
		}
		i++;
	}
	return (false);
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
