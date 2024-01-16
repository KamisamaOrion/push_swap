/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:04:22 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/11 23:08:19 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		*ft_parsing(int ac, char **av);
void	push(int *pile1, int *pile2);
void	sa(int *pile);
void	sb(int *pile);
void	ss(int *pile1, int *pile2);
void	ra(int *pile);
void	rb(int *pile);
void	rr(int *pile1, int *pile2);
void	rra(int *pile);
void	rrb(int *pile);
void	rrr(int *pile1, int *pile2);
int		*push_swap(int *pile1);
int		*ft_tri(int	*pile1, int	*pile2);
int		ind_min(int min, int *pile);
int		found_place(int indice, int **tab1, int **tab2);
void	pb(int *pile1, int *pile2);
void	pa(int *pile1, int *pile2);
void	print_pile(int	*pile);
int		get_place(int **pile1, int **pile2, int indice);
int		*ft_pars_2(char **av);
int		double_rotate(int **pile1, int **pile2, int indice, int place);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_strlen(char *s);
int		ft_search(int **tab1, int **tab2, int indice, int count, int place);

#endif
