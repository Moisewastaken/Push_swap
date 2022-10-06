/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:33:59 by mcochin           #+#    #+#             */
/*   Updated: 2022/09/12 17:32:52 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_a	*head_a;
	t_b	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (0);
	fill_a(&head_a, argc, argv);
	main_sort(&head_a, &head_b);
	a_free(&head_a);
	b_free(&head_b);
}
/*
void	ft_print_list(t_a *head_a, t_b *head_b)
{
	t_a *tmpa;
	t_b *tmpb;

	tmpa = head_a;
	tmpb = head_b;
	ft_printf("--------\n");
	while (tmpa || tmpb)
	{
		if (tmpa && tmpb)
			ft_printf("  %d  %d  \n", tmpa->value, tmpb->value);
		else if (tmpa)
			ft_printf("  %d      \n", tmpa->value);
		else if (tmpb)
			ft_printf("      %d  \n", tmpb->value);
		if (tmpa)
			tmpa = tmpa->next;
		if (tmpb)
			tmpb = tmpb->next;
	}
	ft_printf("  -  -  \n");
	ft_printf("  a  b  \n");
	ft_printf("--------\n");
}*/
