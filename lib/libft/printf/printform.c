/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:02 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/06 14:10:42 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_print_digit(long nb, int base, int m)
{
	int		ct;
	char	*formatmin;
	char	*formatmaj;

	ct = 0;
	formatmin = "0123456789abcdef";
	formatmaj = "0123456789ABCDEF";
	if (nb < 0 && base == 10)
	{
		write(1, "-", 1);
		return (ft_print_digit(-nb, base, m) + 1);
	}
	if (nb < base && m == 0)
		return (ft_print_char(formatmin[nb]));
	if (nb < base && m == 1)
		return (ft_print_char(formatmaj[nb]));
	else
	{
		ct = ft_print_digit(nb / base, base, m);
		return (ft_print_digit(nb % base, base, m) + ct);
	}
}

static int	ft_print_adressbis(unsigned long long nb)
{
	unsigned long long	*adrss;
	int					ct;
	char				*format;

	ct = 0;
	adrss = &nb;
	format = "0123456789abcdef";
	if (nb < 16)
		return (ft_print_char(format[nb]));
	else
	{
		ct = ft_print_adressbis(nb / 16);
		return (ft_print_adressbis(nb % 16) + ct);
	}
}

int	ft_print_adress(unsigned long long nb)
{
	int	ct;

	ct = 0;
	if (nb == 0)
		return (ft_print_str("(nil)"));
	ct += write(1, "0x", 2);
	ct += ft_print_adressbis(nb);
	return (ct);
}
