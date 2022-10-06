/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:39:52 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/02 16:08:18 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_insert_top(t_b **head, int value)
{
	t_b	*new;

	new = malloc(sizeof(t_b));
	new->value = value;
	new->next = *head;
	*head = new;
}

void	b_insert_bottom(t_b **head, int value)
{
	t_b	*new;
	t_b	*tmp;

	new = malloc(sizeof(t_b));
	tmp = *head;
	new->value = value;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	b_print_list(t_b *head)
{
	t_b	*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

void	b_free(t_b **head)
{
	t_b	*tmp;

	if (*head)
	{
		while (*head)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
		*head = NULL;
	}
}
