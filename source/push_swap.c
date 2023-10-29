#include "push_swap.h"

bool	init_stack(t_stack **a, int *nbr_array, int size)
{
	int			i;
	t_stack 	*prev_node;

	*a = (t_stack *)malloc(sizeof(t_stack));
	if (!*a)
		return (false);
	*a.size = size;
	i = 0;
	while (i < size)
	{
		*(a).index = i;
		*(a)->value = nbr_array[i];
		*(a)->prev = NULL;
		*(a)->next = NULL;
		if (i != 0)
			*(a)->prev = prev_node;
		else if (i != size - 1)
			prev_node->next = *a;
		prev_node = *a;
		i++;
	}
	return (true);
}

void	print_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		ft_dprintf(1, "%d: %d\n", s->index, s->value);
		s = s->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	int	*nbr_array;
	int	size;
	t_stack	*a;

	size = parse_input_number(&nbr_array, argc, argv);
	if (size == -1)
	{
		ft_dprintf(1, "Error\n");
		return (-1);
	}
	init_stack(&a, nbr_array, size);
	print_stack(a);
}
