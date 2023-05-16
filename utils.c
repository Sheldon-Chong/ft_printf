/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:40:34 by shechong          #+#    #+#             */
/*   Updated: 2023/05/16 11:40:35 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

void	recur(char *base, unsigned long nbr, unsigned long *count)
{
	unsigned long	baselen;

	baselen = 0;
	while (base[baselen] != '\0')
		baselen ++;
	if (nbr >= baselen)
		recur(base, nbr / baselen, count);
	write(1, &base[nbr % baselen], 1);
	(*count) += 1;
}

int	ft_nbrbase(unsigned long nbr, char *base)
{
	int				len;
	int				i;
	unsigned long	count;

	len = 0;
	i = 0;
	count = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	recur (base, nbr, &count);
	return (count);
}

int	countdigits(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		i ++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
	i += countdigits(n);
	return (i);
}
