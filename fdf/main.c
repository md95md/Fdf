/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:29 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/07 15:07:29 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*img;

	if (argc != 2)
		exit(1);
	mlx = mlx_init(3840, 2160, "FDF", true);
	if (!mlx)
		exit(1);
	img = mlx_new_image(mlx, 3840, 2160);
	if (!img)
	{
		mlx_terminate(mlx);
		exit(1);
	}
	draw_stars(img);
	mlx_image_to_window(mlx, img, 0, 0);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		free_error_points(map);
		exit(1);
	}
	read_map(map, argv);
	smooth_scale(map);
	map->param.z_scale = 1.0;
	map->param.shift_x = 0;
	map->param.shift_y = 0;
	read_map(map, argv);
	calculate_offsets(map, WIN_WIDTH, WIN_HEIGHT);
	map->mlx = img;
	draw_map_array(img, map);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	free_error_points(map);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}

void	draw_stars(mlx_image_t *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < 2160)
	{
		x = 0;
		while (x < 3840)
		{
			mlx_put_pixel(img, x, y, 0x000000FF);
			if (rand() % 2000 == 0)
				mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	smooth_scale(t_map *map)
{
	if (map->height > 500)
	{
		map->param.scale = 1.0;
	}
	else if (map->height <= 500 && map->height > 100)
	{
		map->param.scale = 1.0 + (7.0 - 1.5) * (500 - map->height)
			/ (500 - 100);
	}
	else if (map->height <= 100 && map->height >= 20)
	{
		map->param.scale = 7.0 + (30.0 - 5.0) * (100 - map->height)
			/ (100 - 20);
	}
	else if (map->height < 20 && map->height > 1)
		map->param.scale = 30.0 + (50.0 - 30.0) * (20 - map->height) / (20 - 1);
	else
		map->param.scale = 5.0;
}
