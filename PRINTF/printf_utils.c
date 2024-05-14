/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:17:13 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/14 15:39:10 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*tipe_finder(char c)
{
	char	*p;

	p = "csdi%";
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (0);
}

int	putstr_c(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (*s)
	{
		if (write(1, s, 1) < 0)
			return (-1);
		s++;
		i++;
	}
	return (i);
}

int	putchar_c(char c)
{
	if (write (1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	write_nbr(int n, int count)
{
	char	c;

	if (n < 0)
	{
		if (write (1, "-", 1) < 0)
			return (-1);
		n = -n;
		count++;
	}
	if (n > 9)
	{
		count = write_nbr((n / 10), ++count);
		if (count < 0)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write (1, &c, 1) < 0)
		return (-1);
	return (count);
}

int	putnbr_c(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		if (write (1, "-2147483648", 11) < 0)
			return (-1);
		return (11);
	}
	else
		count = write_nbr(n, count);
	return (count);
}
