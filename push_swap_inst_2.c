/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:11:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/21 22:13:11 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *pile)
{
	int	i;
	int	save;
	int	tmp;

	i = 1;
	save = pile[1];
	pile[i] = pile[pile[0]];
	while (i < pile[0])
	{
		tmp = pile[i + 1];
		pile[i + 1] = save;
		save = tmp;
		i++;
	}
}

void	rrb(int *pile)
{
	int	i;
	int	save;
	int	tmp;

	i = 1;
	save = pile[1];
	pile[i] = pile[pile[0]];
	while (i < pile[0])
	{
		tmp = pile[i + 1];
		pile[i + 1] = save;
		save = tmp;
		i++;
	}
}

void	rrr(int *pile1, int *pile2)
{
	rra(pile1);
	rrb(pile2);
}

void	rr(int *pile1, int *pile2)
{
	ra(pile1);
	rb(pile2);
}

void	rb(int *pile)
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
