#include "push_swap.h"

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
		if (ft_atol(arr[i]) > INT32_MAX || ft_atol(arr[i]) < INT32_MIN)
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
	i = 0;
	while (tmp[i])
	{
		if (ft_atol(tmp[i]) > INT32_MAX || ft_atol(tmp[i]) < INT32_MIN)
		{
			free(*nbr_array);
			return (-1);
		}
		(*nbr_array)[i] = ft_atol(tmp[i]);
		i++;
	}
	free_array((void **)tmp, -1);
	return (i);
}

int	parse_input_number(int **nbr_array, int argc, char **argv)
{
	int	count;

	if (argc == 1)
		return (-1);
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
