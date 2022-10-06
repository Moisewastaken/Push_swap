/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:03:16 by mcochin           #+#    #+#             */
/*   Updated: 2022/08/12 19:06:06 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (size > 0)
	{
		if (!ptr)
			return (malloc(size));
		new_ptr = malloc(size);
		if (new_ptr)
		{
			ft_memcpy(new_ptr, ptr, size);
			free(ptr);
		}
	}
	return (new_ptr);
}
