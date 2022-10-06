/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:46:08 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 14:38:45 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

/*	STRUCTS	 */

typedef struct s_a
{
	int			value;
	struct s_a	*next;
}	t_a;

typedef struct s_b
{
	int			value;
	struct s_b	*next;
}	t_b;

/*	UTILS	*/

void	fill_a(t_a **head, int argc, char **argv);
char	*get_str(int argc, char **argv);
char	*get_error(char *str);
void	ft_error(t_a **head, char **tab, char *str);
long	ft_atol(const char *nptr);
char	*ft_strjoin_spaced(char *s1, char *s2);
int		check_duplicate(t_a *head, int nb);
int		check_a_sorted(t_a *head);
int		check_b_sorted(t_b *head);
int		get_lower(t_a *head);
int		get_a_size(t_a *head);
int		get_b_size(t_b *head);

/*	SORT	*/

void	main_sort(t_a **head_a, t_b **head_b);
void	sort3(t_a **head_a);
void	sort10(t_a **head_a, t_b **head_b);
int		*sort_in_tab(t_a *head);
void	push_b(t_a **head_a, t_b **head_b, int index);
void	push_a(t_a **head_a, t_b **head_b, int index);
void	sort_big(t_a **head_a, t_b **head_b, int partition);
int		get_lower_than(t_a *head, int nb);	
int		get_higher(t_b *head);
void	radix(t_a **head_a, t_b **head_b);
int		get_index(int nb, int *tab);
int		get_bits(int nb);

/*	LIST UTILS	*/

void	a_insert_top(t_a **head, int value);
void	a_insert_after(t_a *node, int value);
void	a_insert_bottom(t_a **head, int value);
void	a_print_list(t_a *head);
void	a_free(t_a **head);
void	b_insert_top(t_b **head, int value);
void	b_insert_after(t_b *node, int value);
void	b_insert_bottom(t_b **head, int value);
void	b_print_list(t_b *head);
void	b_free(t_b **head);
void	ft_print_list(t_a *head_a, t_b *head_b);

/*	INSTRUCTIONS	*/

void	sa(t_a **head);
void	sb(t_b **head);
void	pa(t_a **head_a, t_b **head_b);
void	pb(t_b **head_b, t_a **head_a);
void	ra(t_a **head);
void	rb(t_b **head);
void	rra(t_a **head);
void	rrb(t_b **head);

#endif
