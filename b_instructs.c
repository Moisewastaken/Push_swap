/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:45:48 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/05 14:17:13 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_b **head)
{
	t_b	*next;

	next = (*head)->next;
	(*head)->next = next->next;
	next->next = *head;
	*head = next;
	ft_printf("sb\n");
}

void	pb(t_b **head_b, t_a **head_a)
{
	t_a	*tmp;

	if (!(*head_a))
		return ;
	b_insert_top(head_b, (*head_a)->value);
	tmp = (*head_a)->next;
	free(*head_a);
	*head_a = tmp;
	ft_printf("pb\n");
}

void	rb(t_b **head)
{
	t_b	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
	ft_printf("rb\n");
}

void	rrb(t_b **head)
{
	t_b	*last;
	t_b	*plast;

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
	ft_printf("rrb\n");
}
