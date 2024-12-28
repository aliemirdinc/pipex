/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:19:07 by aldinc            #+#    #+#             */
/*   Updated: 2024/10/15 15:19:08 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	fill_string(char *dizi, long nbr, int i)
{
	while (nbr > 0)
	{
		dizi[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

static void	handle_negativity(char *dizi, int *n, long *nbr)
{
	if (*n == -2147483648)
	{
		*n = -214748364;
		dizi[10] = '8';
	}
	if (*n < 0)
	{
		dizi[0] = '-';
		*nbr = -(*nbr);
	}
}

char	*ft_itoa(int n)
{
	char	*dizi;
	int		i;
	long	nbr;

	i = numlen(n);
	dizi = (char *)malloc((sizeof(char)) * (i + 1));
	if (!dizi)
		return (NULL);
	dizi[i--] = '\0';
	nbr = n;
	handle_negativity(dizi, &n, &nbr);
	if (n == 0)
		dizi[0] = '0';
	else
		fill_string(dizi, nbr, i);
	return (dizi);
}
