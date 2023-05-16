/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:21:09 by shechong          #+#    #+#             */
/*   Updated: 2023/05/16 11:21:10 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_putstr(char *s);
int	ft_nbrbase(unsigned long nbr, char *base);
int	print_address(uintptr_t ptr);
int	ft_printf(const char *s, ...);
int	ft_putnbr(int n);
int	ft_putchar(int c);

#endif
