/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:29 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/05 18:29:28 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(mlx_image_t *img);

void	calculate_offsets(t_map *map, float win_width, float win_height)
{
	map->param.shift_x = win_width / 2;
	map->param.shift_y = win_height / 2;
}

int	main(int argc, char **argv)
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*img;

	if (argc != 2)
		exit(1);
	mlx = mlx_init(3840, 2160, "Test", true);
	if (!mlx)
		exit(1);
	img = mlx_new_image(mlx, 3840, 2160);
	if (!img)
	{
		mlx_terminate(mlx);
		exit(1);
	}
	draw_background(img);
	mlx_image_to_window(mlx, img, 0, 0);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		exit(1);
	}
	float win_width = 3840;
	float win_height = 2160;
	map->param.scale = 0.5;
    map->param.z_scale = 1.0;
    map->param.shift_x = 0;
    map->param.shift_y = 0;
	read_map(map, argv);
	calculate_offsets(map, win_width, win_height); // Calculate the offsets
	map->mlx = img;
	draw_map_array(img, map);
	mlx_key_hook(mlx, my_keyhook, NULL); //press any key - opens two more windows
	mlx_loop(mlx);
	free_error_points(map);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}

void	draw_background(mlx_image_t *img)
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
			x++;
		}
		y++;
	}
}
