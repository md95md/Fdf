/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:22:30 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/05 14:51:04 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	result;

	result = nmemb * size;
	if (result != 0 && result / nmemb != size)
		return (NULL);
	mem = malloc(result);
	if (mem == 0)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
