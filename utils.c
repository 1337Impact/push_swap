/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:19:34 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/19 11:02:23 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*arr_to_stack(int ac, char **av)
{
	t_stack	*hold;
	t_stack	*new;

	new = ft_lstnew(ft_atoi(av[--ac]));
	if (ac < 2)
		return (new);
	while (--ac > 0)
	{
		hold = ft_lstnew(ft_atoi(av[ac]));
		hold->next = new;
		new = hold;
	}
	return (hold);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*stack_to_tab(t_stack *stack, int size)
{
	int	*tab;
	int	i;

	tab = malloc(size * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (stack)
	{
		tab[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (tab);
}

void	manage_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_stacks(t_stackab *stackab)
{
	ft_lstclear(&stackab->stack_a);
	ft_lstclear(&stackab->stack_b);
	free(stackab);
}
