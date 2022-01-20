/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_min.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:13:29 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/17 16:03:36 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_MIN_H
# define LST_MIN_H

# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				keynbr;
	struct s_stack	*next;
}			t_stack;

t_stack	*ft_lstnew(int content);
t_stack	*ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstbeforelast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
#endif