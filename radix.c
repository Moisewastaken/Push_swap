/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:07 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 16:45:39 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_a **head_a, t_b **head_b)
{
	int	*sorted;
	int	size;
	int	index_size;
	int	i;
	int	j;

	sorted = sort_in_tab(*head_a);
	size = get_a_size(*head_a);
	index_size = get_bits(size - 1);
	j = 0;
	while (j < index_size)
	{
		i = 0;
		while (i < size)
		{
			if ((get_index((*head_a)->value, sorted) >> j) & 1)
				ra(head_a);
			else
				pb(head_b, head_a);
			i++;
		}
		j++;
		while (*head_b)
			pa(head_a, head_b);
	}
}

int	get_index(int nb, int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != nb)
		i++;
	return (i + 1);
}

int	get_bits(int nb)
{
	int	i;

	i = 0;
	while (nb >> i)
		i++;
	return (i);
}
