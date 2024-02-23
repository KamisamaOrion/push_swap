/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:17:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/23 19:32:59 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **av)
{
	char	**elt;
	int		i;
	int		j;

	i = 0;
	j = 1;
	elt = ft_split(av[1], ' ');
	while (elt[i])
	{
		while (elt[j])
		{
			if (ft_atoi(elt[j]) == ft_atoi(elt[i]) && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
