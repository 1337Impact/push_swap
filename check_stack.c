/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:23:29 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/18 19:46:19 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	check_params(char **params)
{
	int	i;

	while (*(++params))
	{
		if (ft_atoi(*params) > 2147483647 || ft_atoi(*params) < -2147483648)
			manage_error();
		if (ft_atoi(*params) < 0)
		{
			if (ft_nbrlen(ft_atoi(*params)) != (int)ft_strlen(*params))
				manage_error();
		}
		else
			if ((ft_nbrlen(ft_atoi(*params)) != (int)ft_strlen(*params))
				|| !ft_isdigit(**params))
				manage_error();
		i = 1;
		while (params[i])
		{
			if (ft_atoi(*params) == ft_atoi(params[i++]))
				manage_error();
		}
	}
}
