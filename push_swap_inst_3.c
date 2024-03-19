/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:13:42 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/21 22:13:52 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *pile)
{
	int	i;
	int	save;
	int	tmp;

	i = pile[0];
	save = pile[i];
	pile[i] = pile[1];
	while (i > 1)
	{
		tmp = pile[i - 1];
		pile[i - 1] = save;
		save = tmp;
		i--;
	}
}
