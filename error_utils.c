/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:45:54 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/02 18:11:55 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_a *head, int nb)
{
	t_a	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	int		minus;

	minus = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			minus = -1;
	while (nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * minus);
}

char	*ft_strjoin_spaced(char *s1, char *s2)
{
	char	*buff;
	int		i;
	int		y;

	buff = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!buff)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i])
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = ' ';
	i++;
	while (s2[y])
	{
		buff[i] = s2[y];
		i++;
		y++;
	}
	return (buff);
}
