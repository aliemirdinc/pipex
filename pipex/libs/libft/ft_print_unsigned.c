/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:10:30 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/07 13:46:49 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchr(char s)
{
	if (write(1, &s, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_putnbr2(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 10)
	{
		i += ft_putchr(nbr + '0');
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	return (i);
}

int	ft_print_unsigned(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr == 0)
		return (ft_putchr('0'));
	len = ft_putnbr2(unbr);
	return (len);
}
