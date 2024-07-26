/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:28:19 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/16 13:22:48 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Function to draw in the center of the window
void	calculate_offsets(t_map *map, float win_width, float win_height)
{
	map->param.shift_x = WIN_WIDTH / 2 - 100;
	map->param.shift_y = WIN_HEIGHT / 2 - map->height * map->param.scale
		/ 2 - 100;
}

void	shift_point(t_point *p, t_map *map)
{
	p->x += map->param.shift_x;
	p->y += map->param.shift_y;
}

void	apply_projections_and_shift(t_point *p, t_map *map)
{
	isometric_projection(p);
	shift_point(p, map);
}

/* Linear Interpolation(y) = y1 + (x − x1) * (y2 − y1) / (x2 − x1)
x1, y1 - first coordinates
x2, y2 - second coordinates
x is the point to perform the interpolation
y is the interpolated value */
void	smooth_scale(t_map *map)
{
	if (map->height > 300)
	{
		map->param.scale = 1.0;
	}
	else if (map->height <= 300 && map->height > 50)
	{
		map->param.scale = 1.0 + (7.0 - 1.0) * (300 - map->height)
			/ (300 - 50);
	}
	else if (map->height <= 50 && map->height >= 20)
	{
		map->param.scale = 7.0 + (30.0 - 7.0) * (50 - map->height)
			/ (50 - 20);
	}
	else if (map->height < 20 && map->height > 1)
		map->param.scale = 30.0 + (50.0 - 30.0) * (20 - map->height) / (20 - 1);
	else
		map->param.scale = 5.0;
}
