/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:52:38 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/05 15:32:16 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	result;

	result = 0;
	while (n--)
	{
		if (*s1 != *s2)
		{
			result = (unsigned char)*s1 - (unsigned char)*s2;
			return (result);
		}
		if (*s1 == '\0')
		{
			break ;
		}
		s1++;
		s2++;
	}
	return (0);
}
