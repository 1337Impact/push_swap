/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:25:56 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/13 12:31:00 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_min.h"

t_stack	*ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return (0);
	if (!*lst)
	{
		new->next = NULL;
		return (new);
	}
	new->next = *lst;
	*lst = new;
	return (*lst);
}
