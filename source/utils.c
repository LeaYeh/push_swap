
#include "push_swap.h"

int	get_array_len(void **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	*copy_nbr(int *nbr_array, int idx)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = nbr_array[idx];
	return (num);
}

bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

int	*copy_nbr_array(int *nbr_array, int size)
{
	int	i;
	int	*new_array;

	new_array = (int *)malloc(sizeof(int) * size);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_array[i] = nbr_array[i];
		i++;
	}
	return (new_array);
}
