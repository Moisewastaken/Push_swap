/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:50:59 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 17:32:29 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_a **head_a, t_b **head_b, int partition)
{
	int	index;
	int	*sorted;
	int	size;
	int	i;

	sorted = sort_in_tab(*head_a);
	size = get_a_size(*head_a);
	index = size / partition;
	i = 0;
	while (i < (size / partition) * (partition - 1))
	{
		push_b(head_a, head_b, get_lower_than(*head_a, sorted[index]));
		if (i == index)
			index = index + size / partition;
		i++;
	}
	while (*head_a)
		push_b(head_a, head_b, get_lower(*head_a));
	while (*head_b)
		push_a(head_a, head_b, get_higher(*head_b));
	free(sorted);
	return ;
}

void	push_b(t_a **head_a, t_b **head_b, int index)
{
	int	prox;
	int	size;

	size = get_a_size(*head_a);
	prox = size / 2 + 1;
	if (index == 1)
		pb(head_b, head_a);
	else if (index <= prox)
	{
		while (index-- > 1)
			ra(head_a);
		pb(head_b, head_a);
	}
	else
	{
		while (index++ <= size)
			rra(head_a);
		pb(head_b, head_a);
	}
}

void	push_a(t_a **head_a, t_b **head_b, int index)
{
	int	prox;
	int	size;

	size = get_b_size(*head_b);
	prox = size / 2 + 1;
	if (index == 1)
		pa(head_a, head_b);
	else if (index <= prox)
	{
		while (index-- > 1)
			rb(head_b);
		pa(head_a, head_b);
	}
	else
	{
		while (index++ <= size)
			rrb(head_b);
		pa(head_a, head_b);
	}
}

int	get_lower_than(t_a *head, int nb)
{
	t_a	*tmp;
	int	index;

	tmp = head;
	index = 1;
	while (tmp)
	{
		if (tmp->value <= nb)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

int	*sort_in_tab(t_a *head)
{
	int	*tab;
	int	limits[2];
	int	i;
	t_a	*tmp;

	tab = malloc(sizeof(int) * get_a_size(head));
	tmp = head;
	i = 0;
	limits[0] = INT_MIN;
	limits[1] = INT_MAX;
	while (i < get_a_size(head))
	{
		if (tmp->value < limits[1] && tmp->value > limits[0])
			limits[1] = tmp->value;
		tmp = tmp->next;
		if (!tmp)
		{
			tab[i] = limits[1];
			limits[0] = limits[1];
			limits[1] = INT_MAX;
			i++;
			tmp = head;
		}
	}
	return (tab);
}
