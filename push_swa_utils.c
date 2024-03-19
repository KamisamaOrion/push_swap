/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swa_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:15:47 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 19:49:08 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_min(int	*pile)
{
	int	min;
	int	i;

	min = pile[1];
	i = 2;
	while (i <= pile[0])
	{
		if (min > pile[i])
			min = pile[i];
		i++;
	}
	return (min);
}

int	get_max(int *pile)
{
	int	max;
	int	i;

	max = pile[1];
	i = 2;
	while (i <= pile[0])
	{
		if (max < pile[i])
			max = pile[i];
		i++;
	}
	return (max);
}

int	ind_min(int min, int *pile)
{
	int	i;

	i = 1;
	while (pile[i] != min)
		i++;
	return (i);
}

int	get_place(int **pile1, int **pile2, int indice)
{
	int	place;
	int	i;
	int	boole;

	boole = 0;
	i = ind_min(get_min(*pile1), *pile1);
	place = i;
	while ((place != i || boole == 0) && (*pile2)[indice] > (*pile1)[place])
	{
		if (place == (*pile1)[0])
			place = 1;
		else
			place++;
		boole = 1;
	}
	return (place);
}
