/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: S24/06/25 12:38:18 by agaleeva          #+#    #+#             */
/*   Updated: S24/07/02 14:55:42 by agaleeva         ###   ########.fr       */
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

int	ft_mod(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	draw_line(float x, float y, float x1, float y1, t_map *map)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = map->matrix[(int)y / S][(int)x/ S];
	z1 = map->matrix[(int)y1 / S][(int)x1 / S];
	if (z > 0 || z1 > 0)
		map->color = 0xFF0000FF;
	else if (z == 0 || z1 == 0)
		map->color = 0x0000FFFF;
	else if (z < 0 || z1 < 0)
		map->color = 0x00FF00FF;
	// isometric(&x, &y, z);
	// isometric(&x1, &y1, z1);
	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_mod((int)x_step), ft_mod((int)y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(map->mlx, x, y, map->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_map_array(mlx_image_t *img, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(x * S, y * S, (x + 1) * S, y * S, map);
			if (y < map->height - 1)
				draw_line(x * S, y * S, x * S, (y + 1) * S, map);
			x++;
		}
		y++;
	}
}
