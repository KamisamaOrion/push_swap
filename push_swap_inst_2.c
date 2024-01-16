/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:11:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/11 22:45:30 by mhervoch         ###   ########.fr       */
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
	//printf("rra\n");	
	//write(1, "rra\n", 4);
}

void	rrb(int *pile)
{
	int	i;
	int	save;
	int	tmp;

	i = 1;
	save = pile[1];
	pile[i] = pile[pile[0]];
	while(i < pile[0])
	{
		tmp = pile[i + 1];
		pile[i + 1] = save;
		save = tmp;
		i++;
	}
	//printf("rrb\n");
	//write(1, "rrb\n", 4);
}

void	rrr(int *pile1, int *pile2)
{
	rra(pile1);
	rrb(pile2);
	//printf("rrr\n");
	//write(1, "rrr\n", 4);
}
