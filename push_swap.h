/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:04:22 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/13 21:04:54 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		*ft_parsing(int ac, char **av);
void	push_median(int **pile1, int **pile2, int mediane);
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
int		ft_search(int **tab1, int **tab2, int indice, int count);
int		get_min(int *pile);
int		get_max(int *pile);
void	ft_action(int **pile1, int **pile2, char *action);
int		is_nbr(char *s);
int		ft_atoi(const char *nptr);
int		is_char(char c);
int		*ft_parsing(int ac, char **av);
int		nb_char(char *s);
int		ft_strstrlen(char **s);
void	feed_pile(int **pile, char **tab);
void	tri_three(int **pile1, int	**pile2);
void	place_in_1(int **pile1, int **pile2, int *place);
void	class_sit(int **pile1, int **pile2, int *indice, int *place);
void	do_rrr(int	**pile1, int **pile2, int *indice, int *place);
void	data_one(int *place, int *indice, int *count);
void	pres(int **pile1, int **pile2);
void	set_indice(int **tab2, int *indice);
void	set_place(int **tab1, int *place);
void	ft_disp(int ac, char **av, int **pile1);
int		get_median(int **pile1);
int		is_median(int **pile1, int num);

#endif
