/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:08 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/14 15:37:31 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	format_print(char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = putchar_c(va_arg(args, int));
	else if (s == 's')
		count = putstr_c(va_arg(args, char *));
/* 	else if (s == 'p')
		count = putptr_c(va_arg(args, unsigned long)); */
	else if (s == 'd' || s == 'i')
		count = putnbr_c(va_arg(args, int));
	/* else if (s == 'u')
		count = putunsint_c(va_arg(args, unsigned int), 1);
	else if (s == 'x')
		count = puthexa_min_c(va_arg(args, int));
	else if (s == 'X')
		count = puthexa_may_c(va_arg(args, int)); */
	else if (s == '%')
		count = putchar_c('%');
	return (count);
}

int	ft_printf(char const *s, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			args;
	int				f;

	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && tipe_finder(s[i + 1]))
		{
			f = format_print(s[++i], args);
			if (f < 0)
				return (-1);
			count += f - 1;
		}
		else
			if (write(1, &s[i], 1) < 0)
				return (-1);
		count++;
	}
	va_end(args);
	return (count);
}
