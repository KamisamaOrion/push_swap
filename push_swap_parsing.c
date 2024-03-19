/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:02:42 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 23:03:28 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr(char *s)
{
	int	i;

	i = 0;
	while ((s[i] && s[i] >= '0' && s[i] <= '9') || \
			(i == 0 && s[i] == '-' && ft_strlen(s) > 1))
		i++;
	if (s[i])
		return (0);
	return (1);
}

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
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * (ac + 1));
	tab[0] = ac - 1;
	j = 1;
	while (j < ac)
	{
		tab[j] = ft_atoi(av[j]);
		j++;
	}
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
