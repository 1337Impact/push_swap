/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:33:35 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/17 14:17:59 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *tab, int n)
{
	int	i;
	int	s;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < n - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			s = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = s;
			sorted = 0;
		}
		i++;
		if ((i == n - 1) && !sorted)
		{
			i = 0;
			sorted = 1;
		}
	}
	return (tab);
}

t_stack	*some_magic(t_stack *stack)
{
	int		size;
	t_stack	*hold;
	int		*tab;
	int		i;

	size = ft_lstsize(stack);
	tab = bubble_sort(stack_to_tab(stack, size), size);
	i = 0;
	while (i < size)
	{
		hold = stack;
		while (hold)
		{
			if (hold->content == tab[i])
			{
				hold->keynbr = i;
				break ;
			}
			hold = hold->next;
		}
		i++;
	}
	free(tab);
	return (stack);
}

t_stackab	*radix_sort(t_stackab *stackab)
{
	int			size;
	int			i;

	stackab->stack_a = some_magic(stackab->stack_a);
	i = 0;
	while (!is_sorted(stackab->stack_a))
	{
		size = ft_lstsize(stackab->stack_a);
		while (size--)
		{
			if ((stackab->stack_a->keynbr >> i & 1) == 0)
				stackab = stack_pa_pb(PB, stackab);
			else
				stackab->stack_a = stack_a_action(RA, stackab->stack_a);
		}
		size = ft_lstsize(stackab->stack_b);
		while (size--)
			stackab = stack_pa_pb(PA, stackab);
		i++;
	}
	return (stackab);
}
