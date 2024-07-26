/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:29 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 20:53:32 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void cleanup(t_map *map, mlx_image_t *img, mlx_t *mlx)
{
    if (map)
        free_error_points(map);
    if (img)
        mlx_delete_image(mlx, img);
    if (mlx)
        mlx_terminate(mlx);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*img;

	if (argc != 2 || !ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		exit(1);
	map = initialize_map();
	mlx = initialize_mlx();
	img = initialize_image(mlx);
	draw_stars(img);
	mlx_image_to_window(mlx, img, 0, 0);
	read_map(map, argv);
	free_error_points(map);
	smooth_scale(map);
	set_param(map);
	read_map(map, argv);
	calculate_offsets(map, WIN_WIDTH, WIN_HEIGHT);
	map->mlx = img;
	draw_map_array(img, map);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	cleanup(map, img, mlx);
}

mlx_t	*initialize_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(3840, 2160, "FDF", true);
	if (!mlx)
		return (NULL);
	return (mlx);
}

mlx_image_t	*initialize_image(mlx_t *mlx)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, 3840, 2160);
	if (!img)
	{
		mlx_terminate(mlx);
		exit(1);
	}
	draw_stars(img);
	mlx_image_to_window(mlx, img, 0, 0);
	return (img);
}

t_map	*initialize_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free_error_points(map);
		exit(1);
	}
	return (map);
}

// valgrind --leak-check=full ./fdf fdf/maps/42.fdf