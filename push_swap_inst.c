/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:56:47 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/03 20:57:35 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *pile1, int *pile2)
{
	int	i;
	int	save;
	int	tmp;

	i = 0;
	save = pile2[1];
	while (++i <= pile2[0])
	{
		tmp = pile2[i + 1];
		pile2[i + 1] = save;
		save = tmp;
	}
	i = pile1[0];
	pile2[1] = pile1[1];
	pile2[0]++;
	save = pile1[i];
	pile1[i] = 0;
	while (i > 1)
	{
		tmp = pile1[i - 1];
		pile1[i - 1] = save;
		save = tmp;
		i--;
	}
	pile1[0]--;
}

void	pa(int *pile1, int *pile2)
{
	int	i;
	int	save;
	int	tmp;

	i = 0;
	save = pile1[1];
	while (++i <= pile1[0])
	{
		tmp = pile1[i + 1];
		pile1[i + 1] = save;
		save = tmp;
	}
	i = pile2[0];
	pile1[1] = pile2[1];
	pile1[0]++;
	save = pile2[i];
	pile2[i] = 0;
	while (i > 1)
	{
		tmp = pile2[i - 1];
		pile2[i - 1] = save;
		save = tmp;
		i--;
	}
	pile2[0]--;
}

void	sa(int *pile)
{
	int	i;

	i = pile[1];
	pile[1] = pile[2];
	pile[2] = i;
}

void	sb(int *pile)
{
	int	i;

	i = pile[0];
	pile[1] = pile[2];
	pile[2] = i;
}

void	ss(int *pile1, int *pile2)
{
	sa(pile1);
	sb(pile2);
}
