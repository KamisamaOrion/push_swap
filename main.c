/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:17:01 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/13 21:22:53 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_tri(int **pile1, int **pile2)
{
	int	ind;

	ind = ind_min(get_min(*pile1), *pile1);
	if (ind <= (*pile1)[0] / 2 + 1)
	{
		while (ind != 1)
		{
			ind--;
			ft_action(pile1, pile2, "ra");
		}
	}
	else
	{
		while (ind != 1)
		{
			if (ind == (*pile1)[0])
				ind = 1;
			else
				ind++;
			ft_action(pile1, pile2, "rra");
		}
	}
}

int	*push_swap(int *pile1)
{
	int	*pile2;
	int	mediane;
	
	mediane = get_median(&pile1);
	pile2 = malloc(sizeof(int) * pile1[0] + 1);
	while (pile1[0] > 3)
		push_median(&pile1, &pile2, mediane);
	ft_tri(pile1, pile2);
	last_tri(&pile1, &pile2);
	free(pile2);
	return (pile1);
}

int	main(int ac, char **av)
{
	int	*tab1;

	ft_disp(ac, av, &tab1);
	if (!tab1)
		return (0);
	push_swap(tab1);
	free(tab1);
}
