/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:29:46 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/16 20:16:36 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_rotate(int **pile1, int **pile2, int indice, int place)
{
	if (indice == 1 || place == 1)
		return (0);
	//if (indice <= (*pile2)[0] / 2 && place <= (*pile1)[0] / 2)
	if ((indice <= (*pile2)[0] / 2 + 1 && place <= (*pile1)[0] / 2 + 1) || (indice <= (*pile2)[0] / 2 + 1 && (((*pile1)[0] - place + 1) >= place - indice)) || (( place <= (*pile1)[0] / 2 + 1 && (((*pile2)[0] - indice + 1) >= indice - place))))
		return (1);
	else if ((indice > (*pile2)[0] / 2 + 1 && place > (*pile1)[0] / 2 + 1) || ( indice > (*pile2)[0] / 2 + 1 && (((*pile1)[0] - place + 1) < place - indice)) || (( place > (*pile1)[0] / 2 + 1 && (((*pile2)[0] - indice + 1) < indice - place))))
		return (2);
	return (0);
}

void	push_median(int **pile1, int **pile2, int mediane, int quartan)
{
	if ((*pile1)[1] > mediane)
	{
		ft_action(pile1, pile2, "pb");
		if ((*pile2)[1] > quartan)
			ft_action(pile1, pile2, "rb");
	}
	else
		ft_action(pile1, pile2, "ra");
}

int	get_median(int **pile1) 
{
	int	s;
	int	e;

	s = 1;
	e = (*pile1)[0];
	while (s <= e)
	{
		if (is_median(pile1, (*pile1)[s]))
			return ((*pile1)[s]);
		s++;
	}
	return (0);
}

int	get_quartan(int **pile1)
{
	int	s;
	int	e;
	
	s = 1;
	e = (*pile1)[0];
	while (s <= e)
	{
		if (is_quartan(pile1, (*pile1)[s]))
			return ((*pile1)[s]);
		s++;
	}
	return (0);
}

int	is_median(int **pile1, int num)
{
	int	i;
	int	h;
	int	l;

	i = 1;
	h = 0;
	l = 0;
	while (i <= (*pile1)[0])
	{
		if ((*pile1)[i] > num)
			h++;
		else if ((*pile1)[i] < num)
			l++;
		i++;
	}
	if ((h - l) >= -1 && (h - l) <= 1)
		return (1);
	return (0);
}

int	is_quartan(int **pile1, int num)
{
	int	i;
	int	h;
	int	l;

	i = 1;
	h = 0;
	l = 0;
	while (i <= (*pile1)[0])
	{
		if ((*pile1)[i] > num)
			h++;
		else if ((*pile1)[i] < num)
			l++;
		i++;
	}
	if ((h - (l / 3)) >= -1 && (h - (l / 3)) <= 1)
		return (1);
	return (0);
}
