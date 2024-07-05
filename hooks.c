/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:54:22 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/05 18:38:54 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Pressing 'ESC' closes the window and exits program (no leaks)

void	zoom_map(t_map *map, double zoom_factor)
{
	map->param.scale *= zoom_factor;
	draw_background(map->mlx);
	draw_map_array(map->mlx, map);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = mlx_init(3840, 2160, "MLX42", true);
	if (!mlx)
		return ;
	t_map	*map = (t_map *)param;
	
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		printf("Zoom in\n");
		zoom_map(map, 2);
	}
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		printf("Zoom out\n");
		zoom_map(map, 0.5);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_terminate(mlx);
		exit(0);
	}
}
