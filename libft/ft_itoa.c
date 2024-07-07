/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:00:21 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/12 12:01:51 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_sconvert(int n, size_t len, char *s)
{
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[len] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup ("-2147483648"));
	if (n == 0)
		return (ft_strdup ("0"));
	len = ft_len(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (s == 0)
		return (NULL);
	if (ft_sconvert(n, len, s))
		return (s);
	return (0);
}
