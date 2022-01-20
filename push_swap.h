/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:59:07 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/19 10:57:46 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "lst_manipulate/lst_min.h"

typedef struct s_stackab
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_stackab;
void		ft_swap(int *a, int *b);
void		check_params(char **params);
t_stack		*stack_a_action(int action, t_stack *stack_a);
t_stack		*stack_b_action(int action, t_stack *stack_b);
t_stackab	*stack_a_b_action(int action, t_stackab *stack);
t_stackab	*stack_pa_pb(int action, t_stackab *stack);
void		manage_error(void);

t_stack		*sort_small(t_stack *stack);
t_stackab	*sort_medium(t_stackab *stackab, int lim);
int			is_sorted(t_stack *stack);
int			*stack_to_tab(t_stack *stack, int size);
t_stackab	*radix_sort(t_stackab *stackab);
t_stack		*arr_to_stack(int ac, char **av);
void		free_stacks(t_stackab *stackab);
#endif
