/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:18:23 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/16 18:31:36 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pars_2(char **av)
{
	int		*pile;
	char	**tab;

	tab = ft_split(av[1], ' ');
	pile = malloc(1 + (ft_strstrlen(tab)) * sizeof(int));
	pile[0] = 0;
	feed_pile(&pile, tab);
	return (pile);
}

void	ft_disp(int ac, char **av, int **pile1)
{
	if (ac == 2)
		*pile1 = ft_pars_2(av);
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	else
		*pile1 = ft_parsing(ac, av);
	/*if (!check_error(pile1))
	{
		//error
	}*/
}

int	ft_strstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	feed_pile(int **pile, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < ft_strstrlen(tab))
	{
		(*pile)[j] = atoi(tab[i]);
		(*pile)[0]++;
		i++;
		j++;
	}
}
