/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:56:00 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/19 10:57:36 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "gnl/get_next_line.h"

t_stackab	*checker(t_stackab *stackab, char *instra)
{
	if (!ft_strncmp(instra, "sa", 3))
		stackab->stack_a = stack_a_action(SA, stackab->stack_a);
	else if (!ft_strncmp(instra, "ra", 3))
		stackab->stack_a = stack_a_action(RA, stackab->stack_a);
	else if (!ft_strncmp(instra, "rra", 3))
		stackab->stack_a = stack_a_action(RRA, stackab->stack_a);
	else if (!ft_strncmp(instra, "sb", 3))
		stackab->stack_b = stack_b_action(SB, stackab->stack_b);
	else if (!ft_strncmp(instra, "rb", 3))
		stackab->stack_b = stack_b_action(RB, stackab->stack_b);
	else if (!ft_strncmp(instra, "rrb", 3))
		stackab->stack_b = stack_b_action(RRB, stackab->stack_b);
	else if (!ft_strncmp(instra, "pa", 3))
		stackab = stack_pa_pb(PA, stackab);
	else if (!ft_strncmp(instra, "pb", 3))
		stackab = stack_pa_pb(PB, stackab);
	else if (!ft_strncmp(instra, "ss", 3))
		stackab = stack_a_b_action(SS, stackab);
	else if (!ft_strncmp(instra, "rr", 3))
		stackab = stack_a_b_action(RR, stackab);
	else if (!ft_strncmp(instra, "rrr", 3))
		stackab = stack_a_b_action(RRR, stackab);
	else
		manage_error();
	return (stackab);
}

int	main(int ac, char **av)
{
	t_stackab	*stackab;
	char		*instraction;

	if (ac < 2)
		return (0);
	check_params(av);
	stackab = malloc(sizeof(t_stackab));
	stackab->stack_a = arr_to_stack(ac, av);
	stackab->stack_b = NULL;
	while (1)
	{
		instraction = ft_strtrim(get_next_line(0), "\n");
		if (!instraction)
			break ;
		stackab = checker(stackab, instraction);
		free(instraction);
	}
	if (is_sorted(stackab->stack_a)
		&& (ft_lstsize(stackab->stack_a) == (ac - 1)))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(stackab);
	return (0);
}
