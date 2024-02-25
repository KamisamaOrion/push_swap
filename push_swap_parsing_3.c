/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:03:38 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/25 21:29:05 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *elt)
{
	if (ft_atol(elt) > 2147483648 || ft_atol(elt) < -2147483647)
		return (0);
	return (1);
}

int	error_synt(char *elt)
{
	int	i;
	int	cpt;

	cpt = 0;
	if (!check_int(elt))
		return (0);
	i = 0;
	while (elt[i])
	{
		if (elt[i] == '-' || elt[i] == '+')
			cpt++;
		i++;
	}
	if (cpt > 1)
		return (0);
	return (1);
}

int	double_elt(char **av, int ac)
{
	char	**elt;
	int		j;
	int		i;

	i = 1;
	elt = av;
	if (ac == 2)
	{
		if (!check_double(av))
			return (0);
	}
	while (av[i])
	{
		j = i + 1;
		while (elt[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(elt[j]) && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error_2(char **av)
{
	int	i;
	
	i = 1;
	while (av[i])
	{
		if (!is_nbr(av[i]) || !error_synt(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_error(char **av, int ac)
{
	char	**elt;
	int		i;
	if (!double_elt(av, ac))
		return (0);
	if (ac > 2)
	{
		if (!check_error_2(av))
			return (0);
	}
	elt = ft_split(av[1], ' ');
	i = 0;
	while (elt[i])
	{
		if (!is_nbr(elt[i]) || !error_synt(elt[i]))
			return (0);
		i++;
	}
	return (1);
}
