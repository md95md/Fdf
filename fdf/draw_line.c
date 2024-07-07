/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 24/06/25 12:38:18 by agaleeva          #+#    #+#             */
/*   Updated: 24/07/02 14:55:42 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define S 40

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	mod(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	draw_line(t_point p0, t_point p1, t_map *map)
{
	float	x_step;
	float	y_step;
	int		max;

	if (p0.z > 0 || p1.z > 0)
		map->color = 0xFF0000FF;
	else if (p0.z == 0 || p1.z == 0)
		map->color = 0x0000FFFF;
	else if (p0.z < 0 || p1.z < 0)
		map->color = 0x00FF00FF;
	x_step = p1.x - p0.x;
	y_step = p1.y - p0.y;
	max = ft_max(mod((int)x_step), mod((int)y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p0.x - p1.x) || (int)(p0.y - p1.y))
	{
		mlx_put_pixel(map->mlx, (int)p0.x, (int)p0.y, map->color);
		p0.x += x_step;
		p0.y += y_step;
	}
}

void	draw_map_array(mlx_image_t *img, t_map *map)
{
	int		y;
	int		x;
	t_point	p0;
	t_point	p1;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			p0 = map->matrix[y][x];
			isometric_projection(&p0);
			shift_p0(&p0, map);
			if (x < map->width - 1)
			{
				p1 = map->matrix[y][x + 1];
				isometric_projection(&p1);
				shift_p1(&p1, map);
				draw_line(p0, p1, map);
			}
			if (y < map->height - 1)
			{
				p1 = map->matrix[y + 1][x];
				isometric_projection(&p1);
				shift_p1(&p1, map);
				draw_line(p0, p1, map);
			}
			x++;
		}
		y++;
	}
}
