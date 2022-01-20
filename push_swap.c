/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:39:18 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/19 10:59:37 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stackab *stackab)
{
	int	size;

	size = ft_lstsize(stackab->stack_a);
	if (size == 2)
		stack_a_action(SA, stackab->stack_a);
	if (size == 3)
		stackab->stack_a = sort_small(stackab->stack_a);
	if (size > 3 && size <= 10)
		stackab = sort_medium(stackab, size - 3);
	if (size > 10)
		stackab = radix_sort(stackab);
	free_stacks(stackab);
}

int	main(int ac, char **av)
{
	t_stackab	*stackab;

	check_params(av);
	if (ac <= 2)
		return (0);
	stackab = malloc(sizeof(t_stackab));
	if (!stackab)
		return (1);
	stackab->stack_a = arr_to_stack(ac, av);
	stackab->stack_b = NULL;
	if (!stackab->stack_a)
	{
		free(stackab);
		return (1);
	}
	if (is_sorted(stackab->stack_a))
	{
		free_stacks(stackab);
		return (0);
	}
	push_swap(stackab);
	return (0);
}
