/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:17:01 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/15 20:13:40 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test(int	*pile1, int *pile2, int len)
{
	int	i;

	i = 0;
	printf("%s", "----------------avant traitement----------------\n");
	while (i < len)
	{
		printf("pile 1, %deme element: %d\n", i, pile1[i]);
		i++;
	}
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	pb(pile1, pile2);
	i = 0;
	printf("%s", "-----------------en attente---------------\n");
	while (i < len)
	{
		printf("pile2, %deme element: %d", i, pile2[i]);
		printf("  |  pile1, %deme element: %d\n", i, pile1[i]);
		i++;
	}
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	pa(pile1, pile2);
	ra(pile2);
	//ft_swap(pile1);
	//ft_rotate(pile1);
	//ft_rev_r(pile1);
	i = 0;
	printf("%s", "----------------apres traitement----------------\n");
	while (i < len)
	{
		printf("pile 2, %deme element: %d", i, pile2[i]);
		printf("  |  pile 1, %deme element: %d\n", i, pile1[i]);
		i++;
	}
	/*
	pb(pile1, pile2);
	//ft_push(pile1, pile2);
	//ft_swap(pile1);
	//ft_rotate(pile1);
	//ft_rev_r(pile1);
	i = 0;
	printf("%s", "----------------apres 2eme traitement----------------\n");
	while (i < len)
	{
		printf("pile 2, %deme element: %d", i, pile2[i]);
		printf("  |  pile 1, %deme element: %d\n", i, pile1[i]);
		i++;
	}
	*/
	free(pile1);
	free(pile2);
}

int	main(int ac, char **av)
{
	int	*tab1;
	//int	*tab2;
	if (ac == 2)
		tab1 = ft_pars_2(av);
	else
		tab1 = ft_parsing(ac, av);
	//tab2 = malloc(sizeof(int) * (ac - 1));
	if (!tab1)
		return (0);
	//ft_test(tab1, tab2, ac);
	push_swap(tab1);
	free(tab1);
	//print_pile(tab1);
}

/*
 * test:
 * -5 3 8 4 6 9 7 1 2 698 72 48 55 63 21 64 81 75
 * -5 3 8 4 6 9 7 1 2
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  8 (2)  |  7
 *  11 (3) |  12
 *  4  (3) |  13
 *  2  (4)
 *  9  (6)
 *  10 (7)
 *  1  (5)
 *  3  (4)
 *  6 (3)
 *  5 (2)
 */
