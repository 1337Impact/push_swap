/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:09:13 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/19 11:02:30 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	s;

	s = *a;
	*a = *b;
	*b = s;
}

t_stack	*stack_a_action(int action, t_stack *stack_a)
{
	t_stack	*hold;
	t_stack	*hold2;

	if (action == SA)
	{
		ft_swap(&(stack_a->content), &(stack_a->next->content));
		ft_putstr_fd("sa\n", 1);
	}
	if (action == RA)
	{
		hold = stack_a->next;
		ft_lstadd_back(&stack_a, stack_a);
		stack_a = hold;
		ft_putstr_fd("ra\n", 1);
	}
	if (action == RRA)
	{
		hold = ft_lstlast(stack_a);
		hold2 = ft_lstbeforelast(stack_a);
		stack_a = ft_lstadd_front(&stack_a, hold);
		hold2->next = NULL;
		ft_putstr_fd("rra\n", 1);
	}
	return (stack_a);
}

t_stackab	*stack_pa_pb(int action, t_stackab *stack)
{
	t_stack	*hold;

	if (action == PA)
	{
		hold = stack->stack_b->next;
		stack->stack_a = ft_lstadd_front(&(stack->stack_a), stack->stack_b);
		stack->stack_b = hold;
		ft_putstr_fd("pa\n", 1);
	}
	if (action == PB)
	{
		hold = stack->stack_a->next;
		stack->stack_b = ft_lstadd_front(&(stack->stack_b), stack->stack_a);
		stack->stack_a = hold;
		ft_putstr_fd("pb\n", 1);
	}
	return (stack);
}

t_stack	*stack_b_action(int action, t_stack *stack_b)
{
	t_stack	*hold;
	t_stack	*hold2;

	if (action == SB)
	{
		ft_swap(&(stack_b->content), &(stack_b->next->content));
		ft_putstr_fd("sb\n", 1);
	}
	if (action == RB)
	{
		hold = stack_b->next;
		ft_lstadd_back(&stack_b, stack_b);
		stack_b = hold;
		ft_putstr_fd("rb\n", 1);
	}
	if (action == RRB)
	{
		hold = ft_lstlast(stack_b);
		hold2 = ft_lstbeforelast(stack_b);
		ft_lstadd_front(&stack_b, hold);
		hold2->next = NULL;
		ft_putstr_fd("rrb\n", 1);
	}
	return (stack_b);
}

t_stackab	*stack_a_b_action(int action, t_stackab *stack)
{
	if (action == SS)
	{
		stack_a_action(SA, stack->stack_a);
		stack_b_action(SB, stack->stack_b);
		ft_putstr_fd("ss\n", 1);
	}
	if (action == RR)
	{
		stack_a_action(RA, stack->stack_a);
		stack_b_action(RB, stack->stack_b);
		ft_putstr_fd("rr\n", 1);
	}
	if (action == RRR)
	{
		stack_a_action(RRA, stack->stack_a);
		stack_b_action(RRB, stack->stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
	return (stack);
}
