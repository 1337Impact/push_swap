/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:50:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/10 11:06:28 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_min.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*hold;

	if (lst == NULL)
		return (NULL);
	hold = lst;
	while (hold->next != NULL)
	{
		hold = hold->next;
	}
	return (hold);
}

t_stack	*ft_lstbeforelast(t_stack *lst)
{
	t_stack	*hold;

	if (lst == NULL)
		return (NULL);
	hold = lst;
	while (hold->next->next != NULL)
	{
		hold = hold->next;
	}
	return (hold);
}
