/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:04:54 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/09 18:45:18 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_min.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (result == NULL)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
