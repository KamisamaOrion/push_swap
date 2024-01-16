/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:56:47 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/11 22:45:14 by mhervoch         ###   ########.fr       */
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
	//write(1, "pb\n", 3);
	//printf("pb\n");
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
	//write(1, "pa\n", 3);
	//printf("pa\n");
}

void	sa(int *pile)
{
	int	i;

	i = pile[1];
	pile[1] = pile[2];
	pile[2] = i;
	//write(1, "sa\n", 3);
	//printf("sa\n");
}

void	sb(int *pile)
{
	int	i;

	i = pile[0];
	pile[1] = pile[2];
	pile[2] = i;
	//write(1, "sb\n", 3);
	//printf("sb\n");
}

void	ss(int *pile1, int *pile2)
{
	sa(pile1);
	sb(pile2);
	//write(1, "ss\n", 3);
	//printf("ss\n");
}

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
	//write(1, "rb\n", 3);
	//printf("ra\n");
}

void	rb(int *pile)
{
	int	i;
	int	save;
	int	tmp;

	i = pile[0];
	save = pile[i];
	pile[i] = pile[1];
	while(i > 1)
	{
		tmp = pile[i - 1];
		pile[i - 1] = save;
		save = tmp;
		i--;
	}
	//write(1, "rb\n", 3);
	//printf("rb\n");
}

void	rr(int *pile1, int *pile2)
{
	ra(pile1);
	rb(pile2);
	//write(1, "rr\n", 3);
	//printf("rr\n");
}

/*
int	main(void)
{
	int	*tab;
	int	*pile;
	int	i;

	i = 1;
	pile = malloc(sizeof(int) * 11);
	tab = malloc(sizeof(int) * 11);
	pile[0] = 1;
	tab[0] = 10;
	printf("%s", "----------------avant traitement----------------\n");
	while (i < 11)
	{
		tab[i] = i + 8;
		printf("pile 1, %deme element: %d\n", i, tab[i]);
		i++;
	}
	//ft_push(tab, pile);
	//ft_swap(tab);
	//ft_rotate(tab);
	ft_rev_r(tab);
	i = 1;
	printf("%s", "----------------apres traitement----------------\n");
	while (i < 11)
	{
		//printf("pile 2, %deme element: %d", i, pile[i]);
		printf("  |  pile 1, %deme element: %d\n", i, tab[i]);
		i++;
	}
	//ft_push(tab, pile);
	//ft_swap(tab);
	//ft_rotate(tab);
	ft_rev_r(tab);
	i = 1;
	printf("%s", "----------------apres 2eme traitement----------------\n");
	while (i < 11)
	{
		//printf("pile 2, %deme element: %d", i, pile[i]);
		printf("  |  pile 1, %deme element: %d\n", i, tab[i]);
		i++;
	}
	free(tab);
	free(pile);
}
*/
