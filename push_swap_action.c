/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:08:02 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/11 22:08:35 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_push(int **pile1, int **pile2, char *action)
{
	if (action[1] == 'a')
		pa(*pile1, *pile2);
	else
		pb(*pile1, *pile2);
}

void	check_rr(int **pile1, int **pile2, char *action)
{
	if (ft_strlen(action) == 2)
		rr(*pile1, *pile2);
	if (action[2] == 'a')
		rra(*pile1);
	if (action[2] == 'b')
		rrb(*pile2);
	if (action[2] == 'r')
		rrr(*pile1, *pile2);
}

void	ft_action(int **pile1, int **pile2, char *action)
{
	if (action[0] == 'p')
	{
		check_push(pile1, pile2, action);
	}
	if (action[0] == 'r')
	{
		if (action[1] == 'a')
			ra(*pile1);
		if (action[1] == 'b')
			rb(*pile2);
		if (action[1] == 'r')
			check_rr(pile1, pile2, action);
	}
	if (action[0] == 's')
	{
		if (action[1] == 'a')
			sa(*pile1);
		else
			sb(*pile2);
	}
	printf("%s\n", action);
}

void	tri_three(int **pile1, int	**pile2)
{
	if ((*pile1)[1] < (*pile1)[2] && (*pile1)[2] > \
			(*pile1)[3] && (*pile1)[3] > (*pile1)[1])
	{
		ft_action(pile1, pile2, "ra");
		ft_action(pile1, pile2, "sa");
	}
	else if ((*pile1)[1] > (*pile1)[2] && (*pile1)[2] < \
			(*pile1)[3] && (*pile1)[3] > (*pile1)[1])
		ft_action(pile1, pile2, "sa");
	else if ((*pile1)[1] > (*pile1)[2] && (*pile1)[2] > \
			(*pile1)[3] && (*pile1)[3] < (*pile1)[1])
		ft_action(pile1, pile2, "sa");
}
