/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:10:15 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/07 13:49:44 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_type(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr
			((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}
