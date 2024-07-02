/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:29 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/02 15:24:41 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	read_map(map, argv);
	map->mlx = img;
	draw_map_array(img, map);
	mlx_loop(mlx);
	free_error_points(map);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}
