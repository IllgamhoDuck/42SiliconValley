#include <assembler.h>

void	debug_print_instructions(t_vector *v)
{
	int		i;
	t_instruction	*item;

	i = 0;
	while (i < v->size)
	{
		item = (t_instruction *)vector_get(v, i);
		i++;
	}
	(void)item;
}

void	debug_print_labels(t_vector *v)
{
	int		i;
	t_label		*item;

	i = 0;
	while (i < v->size)
	{
		item = (t_label *)vector_get(v, i);
		i++;
	}
	(void)item;
}

void	debug_print_darray(char **a)
{
	while(a && *a)
	{
		ft_printf("-> %s\n", *a);
		a++;
	}
}
