/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:19:47 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/17 16:01:46 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_min.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*hold;
	t_stack	*head;

	head = *lst;
	if (!lst || !*lst)
		return ;
	while (*lst && lst)
	{
		hold = (*lst)->next;
		free(*lst);
		*lst = hold;
	}
	head = NULL;
}
