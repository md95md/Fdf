/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:28:19 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/07 14:28:39 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_p0(t_point *p0, t_map *map)
{
	p0->x += map->param.shift_x;
	p0->y += map->param.shift_y;
}

void	shift_p1(t_point *p1, t_map *map)
{
	p1->x += map->param.shift_x;
	p1->y += map->param.shift_y;
}

void	calculate_offsets(t_map *map, float win_width, float win_height)
{
	map->param.shift_x = WIN_WIDTH / 2;
	map->param.shift_y = WIN_HEIGHT / 2 - map->height * map->param.scale / 2;
}
