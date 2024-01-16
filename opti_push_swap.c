/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:29:46 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/15 07:12:08 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_rotate(int **pile1, int **pile2, int indice, int place)
{
	if (indice == 1 || place == 1)
		return (0);
	if (indice <= (*pile2)[0] / 2 + 1 && place <= (*pile1)[0] / 2 + 1)
		return (1);
	else if (indice > (*pile2)[0] / 2 + 1 && place > (*pile1)[0] / 2 + 1)
		return (2);
	return (0);
}
