/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swa_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:31:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 19:57:26 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indice(int **tab2, int *indice)
{
	if (*indice == (*tab2)[0])
		*indice = 1;
	else
		*indice += 1;
}

void	set_place(int **tab1, int *place)
{
	if (*place == (*tab1)[0])
		*place = 1;
	else
		*place += 1;
}

int	data_two(int **tab1, int **tab2, int indice, int place)
{
	int	count;

	count = 0;
	while (place != 1 && indice != 1)
	{
		count++;
		set_indice(tab2, &indice);
		set_place(tab1, &place);
	}
	if (place != 1)
		count += (*tab1)[0] - place + 1;
	if (indice != 1)
		count += (*tab2)[0] - indice + 1;
	count++;
	return (count);
}

int	data_three(int indice, int place, int **tab1, int **tab2)
{
	int	count;

	count = 0;
	if (indice <= (*tab2)[0] / 2 + 1)
		count += indice - 1;
	else
		count += (*tab2)[0] - indice + 1;
	if (place <= (*tab1)[0] / 2 + 1)
		count += place - 1;
	else
		count += (*tab1)[0] - place + 1;
	count++;
	return (count);
}
