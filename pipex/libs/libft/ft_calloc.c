/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:18:30 by aldinc            #+#    #+#             */
/*   Updated: 2024/10/15 15:18:31 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total;
	void	*ptr;

	total = num * size;
	ptr = malloc(total);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, total);
	return (ptr);
}
