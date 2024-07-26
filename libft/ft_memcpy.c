/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:53:26 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/05 15:06:10 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = dest;
	src2 = src;
	if (dest == src)
		return (dest);
	while (n > 0)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		n--;
	}
	return (dest);
}
