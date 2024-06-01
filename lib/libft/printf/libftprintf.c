/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:28:51 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/04 19:48:41 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printform(char conv, va_list ap)
{
	int	ct;

	ct = 0;
	if (conv == 'c')
		ct += ft_print_char(va_arg(ap, int));
	else if (conv == 's')
		ct += ft_print_str(va_arg(ap, char *));
	else if (conv == 'p')
		ct += ft_print_adress(va_arg(ap, unsigned long long));
	else if (conv == 'd')
		ct += ft_print_digit(va_arg(ap, int), 10, 0);
	else if (conv == 'i')
		ct += ft_print_digit(va_arg(ap, int), 10, 0);
	else if (conv == 'u')
		ct += ft_print_digit(va_arg(ap, unsigned int), 10, 0);
	else if (conv == 'x')
		ct += ft_print_digit(va_arg(ap, unsigned int), 16, 0);
	else if (conv == 'X')
		ct += ft_print_digit(va_arg(ap, unsigned int), 16, 1);
	else
		ct += write(1, &conv, 1);
	return (ct);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_printform(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
int	main()
{
	int	i;
	i = printf("HI %c, %i\n", 'A' 12);
	printf("%d caracter(s) printed\n", i);
	i = ft_printf("HI %c, %i\n", 'A' 12);
	ft_printf("%d caracter(s) printed\n", i);
}
*/
