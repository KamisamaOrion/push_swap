/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:17:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 19:40:58 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **av)
{
	char	**elt;
	int		i;
	int		j;

	i = 0;
	elt = ft_split(av[1], ' ');
	if (!elt)
		return (0);
	while (elt[i])
	{
		j = i + 1;
		while (elt[j])
		{
			if (ft_atoi(elt[j]) == ft_atoi(elt[i]) && j != i)
			{
				all_free(elt);
				return (0);
			}
			j++;
		}
		i++;
	}
	all_free(elt);
	return (1);
}

void	all_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_in(char **elt, int i)
{
	while (elt[i])
	{
		if (!is_nbr(elt[i]) || !error_synt(elt[i++]))
		{
			all_free(elt);
			return (0);
		}
	}
	return (1);
}
