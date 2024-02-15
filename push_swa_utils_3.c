/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swa_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:31:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/24 21:32:00 by mhervoch         ###   ########.fr       */
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
