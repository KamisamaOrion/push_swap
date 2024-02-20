/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:04:35 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/20 20:49:44 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(int	*pile)
{
	int	i;

	i = 1;
	while (i <= pile[0])
	{
		printf("\n%d", pile[i]);
		i++;
	}
	printf("\n");
}

int	*ft_share(int *pile, int *tab, int len)
{
	int	i;
	int	len_nb;

	len_nb = pile[0];
	tab[0] = len_nb;
	i = 1;
	while (i <= len_nb)
	{
		tab[i] = pile[i];
		i++;
	}
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int	data_two(int **tab1, int **tab2, int indice, int place)
{
	int	count;

	count = 0;
	while (place != 1 && indice != 1)
	{
		count++;
		set_indice(tab2, &indice);
		set_place(tab1, &place);
	}
	if (place != 1)
		count += (*tab1)[0] - place + 1;
	if (indice != 1)
		count += (*tab2)[0] - indice + 1;
	count++;
	return (count);
}

int	ft_search(int **tab1, int **tab2, int indice, int count)
{
	int	data;
	int	place;

	place = get_place(tab1, tab2, indice);
	data = double_rotate(tab1, tab2, indice, place);
	if (data == 1)
		data_one(&place, &indice, &count);
	else if (data == 2)
		count += data_two(tab1, tab2, indice, place);
	else
	{
		if (indice <= (*tab2)[0] / 2 + 1)
			count += indice - 1;
		else
			count += (*tab2)[0] - indice + 1;
		if (place <= (*tab1)[0] / 2 + 1)
			count += place - 1;
		else
			count += (*tab1)[0] - place + 1;
		count++;
	}
	return (count);
}

void	push_elt(int **pile1, int **pile2, int indice)
{
	int	data;
	int	place;

	place = get_place(pile1, pile2, indice);
	while (indice != 1 || place != 1)
	{
		data = double_rotate(pile1, pile2, indice, place);
		if (data == 1)
		{
			ft_action(pile1, pile2, "rr");
			indice--;
			place--;
		}
		else if (data == 2)
			do_rrr(pile1, pile2, &indice, &place);
		else
			class_sit(pile1, pile2, &indice, &place);
	}
	ft_action(pile1, pile2, "pa");
}

int	*ft_tri(int *pile1, int	*pile2)
{
	int	min_indice;
	int	count;
	int	i;
	int	min;

	tri_three(&pile1, &pile2);
	while (pile2[0] > 0)
	{
		i = 1;
		count = ft_search(&pile1, &pile2, i, 0);
		min_indice = i;
		min = count;
		while (++i < pile2[0])
		{
			count = ft_search(&pile1, &pile2, i, 0);
			if (count < min)
			{
				min_indice = i;
				min = count;
			}
		}
		push_elt(&pile1, &pile2, min_indice);
	}
	return (pile1);
}
