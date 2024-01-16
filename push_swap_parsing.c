/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:02:42 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/15 20:16:03 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i])
		return (0);
	return (1);
}

/*
void	print_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("|%d|\n", tab[i++]);
	}
}
*/

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		sum = sum * 10 + nptr[i] - 48;
		i++;
	}
	return (sum * sign);
}

int	*ft_parsing(int ac, char **av)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * ac);
	j = 1;
	i = 2;
	while (j < ac)
	{
		if (!is_nbr(av[j]))
		{
			write(2, "Error\n", 7);
			return (tab);
		}
		tab[0] = ac - 1;
		tab[i - 1] = ft_atoi(av[j]);
		i++;
		j++;
	}
	//print_tab(tab);
	return (tab);
}

int	is_char(char c)
{
	return (c >= 48 && c <= 57);
}

int	nb_char(char *s)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		if (is_char(s[i]))
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_strstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return(i);
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

void	ft_disp (int ac, char **av, int **pile1)
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
}
