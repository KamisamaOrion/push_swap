/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:18:23 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/25 21:29:16 by mhervoch         ###   ########.fr       */
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

int	ft_disp(int ac, char **av, int **pile1)
{
	if (ac == 1)
		return (2);
	if (!check_error(av, ac))
	{
		write(2, "Error\n", 7);
		return (2);
	}
	if (ac == 2)
		*pile1 = ft_pars_2(av);
	else if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
		*pile1 = ft_parsing(ac, av);
	return (1);
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

long int	ft_atol(const char *str)
{
	long int	final_result;
	int			i;
	int			sign;

	if (!str)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	final_result = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		final_result = final_result * 10 + (str[i] - 48);
		i++;
	}
	if (final_result * sign > 2147483647 || final_result * sign < -2147483648)
		return (2147483650);
	return (final_result * sign);
}
