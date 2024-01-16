/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:04:35 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/15 20:12:16 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_action(int **pile1, int **pile2, char *action)
{
	if (action[0] == 'p')
	{
		if (action[1] == 'a')
			pa(*pile1, *pile2);
		else
			pb(*pile1, *pile2);
	}
	if (action[0] == 'r')
	{
		if (action[1] == 'a')
			ra(*pile1);
		if (action[1] == 'b')
			rb(*pile2);
		if (action[1] == 'r')
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
	}
	if (action[0] == 's')
	{
		if (action[1] == 'a')
			sa(*pile1);
		else
			sb(*pile2);
	}
	//write(1, action, ft_strlen(action));
	//write(1, "\n", 1);
	printf("%s\n", action);
}

void	print_pile(int	*pile)
{
	int	i;

	i = 1;
	//printf("---------------\n");
	while (i <= pile[0])
	{
		printf("\n%d", pile[i]);
		i++;
	}
	printf("\n");
}

int	*push_swap(int *pile1)
{
	int	*pile2;

	pile2 = malloc(sizeof(int) * pile1[0] + 1);
	while (pile1[0] > 3)
		ft_action(&pile1, &pile2, "pb");
	ft_tri(pile1, pile2);
	free(pile2);
	return (pile1);
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

int	get_min(int	*pile)
{
	int	min;
	int	i;

	min = pile[1];
	i = 2;
	while (i <= pile[0])
	{
		if (min > pile[i])
			min = pile[i];
		i++;
	}
	return (min);
}

int	ft_search(int **tab1, int **tab2, int indice, int count, int place)
{
	int data;

	data = double_rotate(tab1, tab2, indice, place);
	if (data == 1)
	{
		if (place < indice)
		{
			count = place - 1;
			indice -= place - 1;
			count += indice - 1;
			count ++; //le push a
		}
		if (place == indice)
			count = indice - 1;
		if (indice < place)
		{
			count = indice - 1;
			place -= indice - 1;
			count += place - 1;
			count++; //le push a
		}
	}
	else if (data == 2)
	{
		while (place != 1 && indice != 1)
		{
			count++;
			if (indice == (*tab2)[0])
				indice = 1;
			else
				indice++;
			if (place == (*tab1)[0])
				place = 1;
			else
				place++;
		}
		if (place != 1)
			count += (*tab1)[0] - place + 1;
		if (indice != 1)
			count += (*tab2)[0] - indice + 1;
	}
	else
	{
		if (indice <= *tab2[0] / 2 + 1)
			count += indice - 1;
		else
			count += *tab2[0] - indice + 1;
		if (place <= *tab1[0] / 2 + 1)
			count += place - 1;
		else
			count += *tab1[0] - place + 1;
		count++;
	}
	return (count);
}

/*
int	found_place(int indice, int **tab1, int **tab2)
{
	int	place;
	int	i;
	int	boole;

	boole = 0;
	i = ind_min(get_min(*tab1), *tab1);
	place = i;
	while (true)
	{
		if (tab1[min] == tab1[*tab1[0] - 1])
			min = 1;
		else
			min++;
		i++;
	}
	return (i);
}
*/

int	ind_min(int	min, int *pile)
{
	int	i;

	i = 1;
	while (pile[i] != min)
		i++;
	return (i);
}

void	tri_three(int **pile1, int	**pile2)
{
	if ((*pile1)[1] < (*pile1)[2] && (*pile1)[2] > (*pile1)[3] && (*pile1)[3] > (*pile1)[1])
	{
		ft_action(pile1, pile2, "ra");
		ft_action(pile1, pile2, "sa");	
	}
	else if ((*pile1)[1] > (*pile1)[2] && (*pile1)[2] < (*pile1)[3] && (*pile1)[3] > (*pile1)[1])
		ft_action(pile1, pile2, "sa");
	else if ((*pile1)[1] > (*pile1)[2] && (*pile1)[2] > (*pile1)[3] && (*pile1)[3] < (*pile1)[1])
		ft_action(pile1, pile2, "sa");
}

int	get_place(int **pile1, int **pile2, int indice)
{
	int	place;
	int	i;
	int	boole;
	
	boole = 0;
	i = ind_min(get_min(*pile1), *pile1);
	place = i;
	while ((place != i || boole == 0) && (*pile2)[indice] > (*pile1)[place])
	{
		if (place == (*pile1)[0])
			place = 1;
		else
			place++;
		boole = 1;
	}
	return (place);
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
		{
			ft_action(pile1,pile2, "rrr");
			if (indice == (*pile2)[0])
				indice = 1;
			else
				indice++;
			if (place == (*pile1)[0])
				place = 1;
			else
				place++;
		}
		else
		{
			if (indice != 1)
			{
				if (indice <= (*pile2)[0] / 2 + 1)
				{
					ft_action(pile1, pile2, "rb");
					indice--;
				}
				else
				{
					if (indice == (*pile2)[0])
						indice = 1;
					else
						indice++;
					ft_action(pile1, pile2, "rrb");
				}
			}
			if (place != 1)
			{
				if (place <= *pile1[0] / 2 + 1)
				{
					ft_action(pile1, pile2, "ra");
					place--;
				}
				else
				{
					if (place == (*pile1)[0])
						place = 1;
					else
						place++;
					ft_action(pile1, pile2, "rra");
				}
			}
		}
	}
	ft_action(pile1, pile2, "pa");
}

int	*ft_tri(int *pile1, int	*pile2)
{
	int	min_indice;
	int	count;
	int	i;
	int	min;
	int place;
	
	tri_three(&pile1, &pile2);
	while (pile2[0] > 0)
	{	
		i = 1;
		place = get_place(&pile1, &pile2, i);
		count = ft_search(&pile1, &pile2, i, 0, place);
		min_indice = i;
		min = count;
		i++;
		while (i < pile2[0])
		{
			place = get_place(&pile1, &pile2, i);
			count = ft_search(&pile1, &pile2, i, 0i, place);
			if (count < min)
			{
				min_indice = i;
				min = count;
			}
			i++;
		}
		//printf("\n%d\n\n", pile2[0]);
		push_elt(&pile1, &pile2, min_indice);
	}
	return (pile1);
}

/*
 * pour optimiser utiliser rrr pour faire rota les deux pile
 * 27 5 1 29 12 19 15 25 30 24 7 3 14 4 20 9 26 23 16 18 6 11 2 17 28 22 21 10 13 8 
 * */
