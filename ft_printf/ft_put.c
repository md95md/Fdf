/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:38:51 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/25 13:23:59 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putptr_helper(unsigned long long n, int *prefix_printed)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (!n)
	{
		*prefix_printed = 0;
		return (ft_printstr("(nil)"));
	}
	if (n >= 16)
	{
		count += ft_putptr_helper(n / 16, prefix_printed);
		count += ft_putchar(symbols[n % 16]);
	}
	else if (n < 16)
	{
		return (ft_putchar(symbols[n]));
	}
	return (count);
}

int	ft_putptr(unsigned long long n)
{
	int	prefix_printed;

	prefix_printed = 0;
	if (n > 0)
	{
		prefix_printed = ft_putchar('0') + ft_putchar('x');
	}
	return (prefix_printed + ft_putptr_helper(n, &prefix_printed));
}

int	ft_putunsgnint(unsigned int n)
{
	return (ft_printdigit(n, 10));
}
