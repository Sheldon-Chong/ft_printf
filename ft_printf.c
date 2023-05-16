/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:40:27 by shechong          #+#    #+#             */
/*   Updated: 2023/05/16 11:40:29 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += print_address(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789");
	else if (format == 'x')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			length += ft_formats(args, s[i + 1]);
			i += 2;
		}
		else
		{
			length += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (length);
}

int	print_address(uintptr_t ptr)
{
	int				length;
	unsigned long	address;

	length = 0;
	address = (unsigned long)ptr;
	length += ft_putstr("0x");
	length += ft_nbrbase(address, "0123456789abcdef");
	return (length);
}
