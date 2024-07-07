/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:48:06 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/07 14:12:52 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	if (!s)
		return (ft_printstr("(null)"));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_puthex(unsigned int n, int flag)
{
	int		count;
	char	*symbols_low;
	char	*symbols_up;

	symbols_low = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, flag);
		if (flag == 1)
			count += ft_putchar(symbols_up[n % 16]);
		else if (flag == 0)
			count += ft_putchar(symbols_low[n % 16]);
	}
	else
	{
		if (flag == 1)
			return (ft_putchar(symbols_up[n]));
		else if (flag == 0)
			return (ft_putchar(symbols_low[n]));
	}
	return (count);
}



int	ft_printdigit(long n, int base)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (count + 1);
	}
	else if (n >= 10)
	{
		count += ft_printdigit(n / base, base);
		ft_putchar(n % base + '0');
		return (count + 1);
	}
	return (0);
}
