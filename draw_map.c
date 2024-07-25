/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:51:00 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/16 13:04:15 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_lines(mlx_image_t *img, t_map *map, int y)
{
	int		x;
	t_point	p0;
	t_point	p1;

	x = 0;
	while (x < map->width)
	{
		p0 = map->matrix[y][x];
		apply_projections_and_shift(&p0, map);
		if (x < map->width - 1)
		{
			p1 = map->matrix[y][x + 1];
			apply_projections_and_shift(&p1, map);
			draw_line(p0, p1, map);
		}
		x++;
	}
}

void	draw_vertical_lines(mlx_image_t *img, t_map *map, int x)
{
	int		y;
	t_point	p0;
	t_point	p1;

	y = 0;
	while (y < map->height)
	{
		p0 = map->matrix[y][x];
		apply_projections_and_shift(&p0, map);
		if (y < map->height - 1)
		{
			p1 = map->matrix[y + 1][x];
			apply_projections_and_shift(&p1, map);
			draw_line(p0, p1, map);
		}
		y++;
	}
}

void	draw_map_array(mlx_image_t *img, t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		draw_horizontal_lines(img, map, y);
		y++;
	}
	x = 0;
	while (x < map->width)
	{
		draw_vertical_lines(img, map, x);
		x++;
	}
}
