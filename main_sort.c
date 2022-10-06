/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:03:19 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/28 19:25:12 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(t_a **head_a, t_b **head_b)
{
	int	size;

	size = get_a_size(*head_a);
	if (!check_a_sorted(*head_a))
		return ;
	if (size <= 3)
		sort3(head_a);
	else if (size <= 10)
		sort10(head_a, head_b);
	else if (size <= 100)
		sort_big(head_a, head_b, 4);
	else if (size <= 200)
		sort_big(head_a, head_b, 8);
	else
		radix(head_a, head_b);
	return ;
}

void	sort3(t_a **head)
{
	int	index;
	int	size;

	index = get_lower(*head);
	size = get_a_size(*head);
	if (!check_a_sorted(*head))
		return ;
	if (size == 2
		|| (index == 2 && (*head)->value < (*head)->next->next->value))
		sa(head);
	else if (index == 1)
	{
		sa(head);
		ra(head);
	}
	else if (index == 2)
		ra(head);
	else if (index == 3 && (*head)->value < (*head)->next->value)
		rra(head);
	else
	{
		sa(head);
		rra(head);
	}
	return ;
}

void	sort10(t_a **head_a, t_b **head_b)
{
	int	index;
	int	prox;
	int	size;

	while (get_a_size(*head_a) > 3)
	{
		index = get_lower(*head_a);
		size = get_a_size(*head_a);
		prox = size / 2 + 1;
		if (index == 1)
			pb(head_b, head_a);
		else if (index <= prox)
			ra(head_a);
		else
			rra(head_a);
	}
	sort3(head_a);
	while (*head_b)
		pa(head_a, head_b);
	return ;
}
