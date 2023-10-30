
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
