/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:17:01 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 21:34:36 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_tri(int *tab1)
{
	int	i;

	i = 0;
	while (tab1[i + 1])
	{
		if (tab1[i + i] < tab1[i])
			return (0);
		i++;
	}
	return (1);
}

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
	int	goal;

	pile2 = malloc(sizeof(int) * pile1[0] + 1);
	if (!pile2)
	{
		free(pile2);
		return (0);
	}
	pile2[0] = 0;
	while (pile1[0] > 3)
	{
		mediane = get_median(&pile1);
		goal = pile1[0] / 2 + 1;
		while (pile1[0] > goal)
			push_median(&pile1, &pile2, mediane);
	}
	ft_tri(pile1, pile2);
	last_tri(&pile1, &pile2);
	free(pile2);
	return (pile1);
}

int	main(int ac, char **av)
{
	int	*tab1;
	int	error;

	error = ft_disp(ac, av, &tab1);
	if (error != 1)
	{
		if (!error)
			free(tab1);
		return (0);
	}
	if (is_tri(tab1))
	{
		free(tab1);
		return (0);
	}
	push_swap(tab1);
	free(tab1);
}
