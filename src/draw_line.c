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
