/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:03:38 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/20 20:41:38 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	check_int(char *elt)
//{
//}

int	error_synt(char *elt)
{
	int	i;
	int	cpt;

	cpt = 0;
	//if (!check_int(elt))
		//return (0);
	i = 0;
	while (elt[i])
	{
		if (elt[i] == '-' || elt[i] == '+')
			cpt++;
	}
	if (cpt > 1)
		return (0);
	return (1);
}

int	check_error(char **av, int ac)
{
	char	**elt;
	int		i;
	
	(void) ac;
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
