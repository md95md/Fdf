/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:58:53 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/05 17:37:28 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//store the original x and y values before changing them
//incorrect calculation for point->y because point->x has already been changed

void	isometric_projection(t_point *point)
{
	float	original_x;
	float	original_y;

	original_x = point->x;
	original_y = point->y;
	point->x = (1 / sqrt(2)) * (original_x - original_y);
	point->y = (original_x / sqrt(2)) + (original_y / sqrt(2)) - point->z;
}
