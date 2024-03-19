/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swa_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:30:21 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/13 21:45:35 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_in_1(int **pile1, int **pile2, int *place)
{
	if (*place <= *pile1[0] / 2 + 1)
	{
		ft_action(pile1, pile2, "ra");
		*place -= 1;
	}
	else
	{
		if (*place == (*pile1)[0])
			*place = 1;
		else
			*place += 1;
		ft_action(pile1, pile2, "rra");
	}
}

void	class_sit(int **pile1, int **pile2, int *indice, int *place)
{
	if (*indice != 1)
	{
		if (*indice <= (*pile2)[0] / 2 + 1)
		{
			ft_action(pile1, pile2, "rb");
			*indice -= 1;
		}
		else
		{
			if (*indice == (*pile2)[0])
				*indice = 1;
			else
				*indice += 1;
			ft_action(pile1, pile2, "rrb");
		}
	}
	if (*place != 1)
		place_in_1(pile1, pile2, place);
}

void	do_rrr(int	**pile1, int **pile2, int *indice, int *place)
{
	ft_action(pile1, pile2, "rrr");
	if (*indice == (*pile2)[0])
		*indice = 1;
	else
		*indice += 1;
	if (*place == (*pile1)[0])
		*place = 1;
	else
		*place += 1;
}

void	data_one(int *place, int *indice, int *count)
{
	if (*place < *indice)
	{
		*count = *place - 1;
		*indice -= *place - 1;
		*place = 1;
		*count += *indice - 1;
		*count += 1;
	}
	if (*place == *indice)
		*count = *indice;
	if (*indice < *place)
	{
		*count = *indice - 1;
		*place -= *indice - 1;
		*indice = 1;
		*count += *place - 1;
		*count += 1;
	}
}

void	pres(int **pile1, int **pile2)
{
	int	i;

	i = ind_min(get_min(*pile1), *pile1);
	while (i != 1)
	{
		if (i <= (*pile1)[0] / 2 + 1)
		{
			i--;
			ft_action(pile1, pile2, "rr");
		}
		else
		{
			if (i == (*pile1)[0])
				i = 1;
			else
				i++;
		}
	}
}
