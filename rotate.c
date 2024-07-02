/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:58:53 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/02 16:06:28 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	isometric(t_point *dot, float angle)
// {
// 	dot->x = (dot->x - dot->y) * cos(angle);
// 	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
// }

void	isometric(float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

// destination.x = source.x + cos(angle) * source.z
// destination.y = source.y + sin(angle) * source.z