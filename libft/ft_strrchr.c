/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:25:02 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/05 15:34:40 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*cs;

	cs = NULL;
	while (*s)
	{
		if (*s == (char)c)
			cs = s;
		s++;
		if ((char)c == 0)
			return ((char *)s + ft_strlen(s));
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)cs);
	return (0);
}
