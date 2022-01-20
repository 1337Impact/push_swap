/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:46:24 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/18 11:53:43 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_min.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*hold;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		hold = *lst;
		while (hold->next != NULL)
		{
			hold = hold->next;
		}
		hold->next = new;
		new->next = 0;
	}
}
