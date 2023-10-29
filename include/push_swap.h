#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int             value;
	int             index;
	int				size;
	struct s_stack  *next;
	struct s_stack  *prev;
}	t_stack;


int	parse_input_number(int **nbr_array, int argc, char **argv);

int	get_array_len(char **arr);

#endif