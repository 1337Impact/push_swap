/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:40:40 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/18 11:30:42 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_nbr(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == nbr)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

t_stack	*sort_small(t_stack *stack)
{
	int	*a;
	int	*b;
	int	*c;

	while (!is_sorted(stack))
	{
		a = &(stack->content);
		b = &(stack->next->content);
		c = &(stack->next->next->content);
		if (*a > *b && *b > *c)
			stack = stack_a_action(RA, stack);
		if (*a < *b && *b > *c)
			stack = stack_a_action(RRA, stack);
		if (*a > *b && *b < *c && *a < *c)
			stack = stack_a_action(SA, stack);
		if (*a > *b && *b < *c && *a > *c)
			stack = stack_a_action(RA, stack);
	}
	return (stack);
}

t_stackab	*sort_medium(t_stackab *stackab, int lim)
{
	int			i;
	int			min_i;

	i = 0;
	while (i++ < lim)
	{
		min_i = index_of_nbr(stackab->stack_a, find_min(stackab->stack_a));
		if (min_i <= 2)
			while (index_of_nbr(stackab->stack_a, find_min(stackab->stack_a)))
				stackab->stack_a = stack_a_action(RA, stackab->stack_a);
		else
			while (index_of_nbr(stackab->stack_a, find_min(stackab->stack_a)))
				stackab->stack_a = stack_a_action(RRA, stackab->stack_a);
		stackab = stack_pa_pb(PB, stackab);
	}
	stackab->stack_a = sort_small(stackab->stack_a);
	i = 0;
	while (i++ < lim)
		stackab = stack_pa_pb(PA, stackab);
	return (stackab);
}
