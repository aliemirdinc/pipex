/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:10:58 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/07 13:48:26 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchr(char s)
{
	if (write(1, &s, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_lowest(int low)
{
	if (low == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return (11);
	}
	return (0);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (ft_lowest(-2147483648));
	if (nbr < 0)
	{
		i += ft_putchr('-');
		nbr = -nbr;
	}
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
