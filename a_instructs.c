/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:58:53 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 16:42:34 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_a **head)
{
	t_a	*next;

	next = (*head)->next;
	(*head)->next = next->next;
	next->next = *head;
	*head = next;
	ft_printf("sa\n");
}

void	pa(t_a **head_a, t_b **head_b)
{
	t_b	*tmp;

	if (!(*head_b))
		return ;
	a_insert_top(head_a, (*head_b)->value);
	tmp = (*head_b)->next;
	free(*head_b);
	*head_b = tmp;
	ft_printf("pa\n");
}

void	ra(t_a **head)
{
	t_a	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
	ft_printf("ra\n");
}

void	rra(t_a **head)
{
	t_a	*last;
	t_a	*plast;

	last = *head;
	plast = NULL;
	while (last->next)
	{
		plast = last;
		last = last->next;
	}
	plast->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("rra\n");
}
