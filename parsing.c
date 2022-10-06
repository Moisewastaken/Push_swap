/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:50 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 16:44:50 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_a **head, int argc, char **argv)
{
	char	*str;
	char	**tab;
	long	nb;
	int		i;

	tab = NULL;
	i = -1;
	str = get_str(argc, argv);
	if (!str)
		ft_error(head, tab, str);
	tab = ft_split(str, ' ');
	while (tab[++i])
	{
		nb = ft_atol(tab[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			ft_error(head, tab, str);
		if (check_duplicate(*head, nb) == 0)
			ft_error(head, tab, str);
		a_insert_bottom(head, nb);
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	return (free(tab), free(str));
}

char	*get_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = malloc(1);
	str[0] = '\0';
	while (++i < argc)
	{
		if (!get_error(argv[i]))
		{
			free(str);
			return (NULL);
		}
		tmp = ft_strjoin_spaced(str, argv[i]);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*get_error(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
			return (NULL);
		if (str[i] == '-' || str[i] == '+')
			if (!ft_isdigit(str[i + 1]) || ft_isdigit(str[i - 1]))
				return (NULL);
	}
	i = -1;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
			return (str);
	return (NULL);
}

void	ft_error(t_a **head, char **tab, char *str)
{
	int	i;

	i = -1;
	if (str)
		free(str);
	if (*head)
		a_free(head);
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
	write(2, "Error\n", 6);
	exit(1);
}
