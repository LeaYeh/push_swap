#include "push_swap.h"

static bool _valid_number(char *str)
{
	int i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	_check_all_number(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!_valid_number(arr[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	_parse_number(int **nbr_array, char **arr, int len)
{
	int	i;

	*nbr_array = (int *)malloc(sizeof(int) * len);
	if (!*nbr_array || !_check_all_number(arr))
		return (-1);
	i = 0;
	while (arr[i])
	{
		(*nbr_array)[i] = ft_atoi(arr[i]);
		i++;
	}
	return (i);
}

static int	_parse_number_from_str(int **nbr_array, char *str)
{
	char	**tmp;
	int		i;

	tmp = ft_split(str, ' ');
	if (!tmp || !_check_all_number(tmp))
		return (-1);
	*nbr_array = (int *)malloc(sizeof(int) * (get_array_len(tmp)));
	if (!nbr_array)
		return (-1);
	i = 0;
	while (tmp[i])
	{
		(*nbr_array)[i] = ft_atoi(tmp[i]);
		i++;
	}
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
	return (count);
}
