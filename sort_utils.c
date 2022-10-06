/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:28:03 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 16:46:08 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lower(t_a *head)
{
	t_a	*cur;
	int	index;
	int	i;
	int	tmp;

	cur = head;
	tmp = INT_MAX;
	i = 1;
	index = 1;
	while (cur)
	{
		if (cur->value < tmp)
		{
			tmp = cur->value;
			index = i;
		}
		i++;
		cur = cur->next;
	}
	return (index);
}

int	get_higher(t_b *head)
{
	t_b	*cur;
	int	index;
	int	i;
	int	tmp;

	cur = head;
	tmp = INT_MIN;
	i = 1;
	index = 1;
	while (cur)
	{
		if (cur->value > tmp)
		{
			tmp = cur->value;
			index = i;
		}
		i++;
		cur = cur->next;
	}
	return (index);
}

int	get_a_size(t_a *head)
{
	t_a	*cur;
	int	i;

	cur = head;
	i = 1;
	while (cur->next)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	get_b_size(t_b *head)
{
	t_b	*cur;
	int	i;

	cur = head;
	i = 1;
	while (cur->next)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	check_a_sorted(t_a *head)
{
	t_a	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->value > tmp->next->value)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}
