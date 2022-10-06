/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:39:52 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/02 18:11:26 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_insert_top(t_a **head, int value)
{
	t_a	*new;

	new = malloc(sizeof(t_a));
	new->value = value;
	new->next = *head;
	*head = new;
}

void	a_insert_bottom(t_a **head, int value)
{
	t_a	*new;
	t_a	*tmp;

	new = malloc(sizeof(t_a));
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

void	a_free(t_a **head)
{
	t_a	*tmp;

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
