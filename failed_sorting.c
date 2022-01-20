#include "push_swap.h"

t_stack	*sort_big1(t_stack *stack)
{
	int	size;
	int	*tab;
	int	i;
	t_stackab	*stackab;

	stackab = malloc(sizeof(t_stackab));
	stackab->stack_a = stack;
	stackab->stack_b = NULL;

	size = ft_lstsize(stack);
	tab = bubble_sort(stack_to_tab(stack, size), size);
	i = 0;
	while (i < size)
	{
		if (index_of_nbr(stackab->stack_a, tab[i]) < ((size - i) / 2))
			while (index_of_nbr(stackab->stack_a, tab[i]))
				stackab->stack_a = stack_a_action(ra, stackab->stack_a);
		else
			while (index_of_nbr(stackab->stack_a, tab[i]))
				stackab->stack_a = stack_a_action(rra, stackab->stack_a);
		stackab = stack_pa_pb(pb, stackab);
		i++;
	}
	i = 0;
	while (i++ < size)
		stackab = stack_pa_pb(pa, stackab);
	return (stackab->stack_a);
}

t_stack	*sort_a(t_stackab *stackab, int size)
{
	int	i;
	int	*tab;

	tab = bubble_sort(stack_to_tab(stackab->stack_a, size), size);
	i = 0;
	while (i < size)
	{
		if (index_of_nbr(stackab->stack_a, tab[i]) < ((size - i) / 2))
			while (index_of_nbr(stackab->stack_a, tab[i]))
				stackab->stack_a = stack_a_action(ra, stackab->stack_a);
		else
			while (index_of_nbr(stackab->stack_a, tab[i]))
				stackab->stack_a = stack_a_action(rra, stackab->stack_a);
		stackab = stack_pa_pb(pb, stackab);
		i++;
	}
	i = 0;
	while (i++ < size)
		stackab = stack_pa_pb(pa, stackab);
	return (stackab->stack_a);
}

t_stack *sort_big(t_stack *stack)
{
	int	size;
	int	*tab;
	int	i;
	t_stackab	*stackab;
	int	key_nbr;

	stackab = malloc(sizeof(t_stackab));
	stackab->stack_a = stack;
	stackab->stack_b = NULL;

	size = ft_lstsize(stack);
	tab = bubble_sort(stack_to_tab(stack, size), size);
	i = 
	key_nbr = tab[size / 4];
	while (i < size)
	{
		if (stackab->stack_a->content <= key_nbr)
			stackab = stack_pa_pb(pb, stackab);
		else
			stackab->stack_a = stack_a_action(ra, stackab->stack_a);
		i++;
		if (!(i < size))
		{
			if (key_nbr == tab[size / 4])
				key_nbr = tab[size / 2];
			else if (key_nbr == tab[size / 2])
				key_nbr = tab[(size / 2) + (size / 4)];
			else if (key_nbr == tab[(size / 2) + (size / 4)])
				key_nbr = tab[size - 1];
			else
				break ;
			i = 0;
		}
		ft_putnbr_fd(size -1, 1);
	}
	i = 0;
	int max;
	stackab->stack_a = sort_a(stackab, ft_lstsize(stackab->stack_a));
	size = ft_lstsize(stackab->stack_b);
	while (--size > 0)
	{
		max = find_min_max(stackab->stack_b, 1);
		if (index_of_nbr(stackab->stack_b, max) < size / 2)
			while (index_of_nbr(stackab->stack_b, max))
				stackab->stack_b = stack_b_action(rb, stackab->stack_b);
		else
			while (index_of_nbr(stackab->stack_b, max))
				stackab->stack_b = stack_b_action(rrb, stackab->stack_b);
		stackab = stack_pa_pb(pa, stackab);
	}
	return(stackab->stack_a);
}
