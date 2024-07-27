/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:29 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/27 19:07:29 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void cleanup(t_map *map, mlx_image_t *img, mlx_t *mlx)
{
    if (map)
	{
        free_error_points(map);
		free(map);
	}
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
	int				fd;

	#include "libft.h" // Include the appropriate header file
	
	if (argc != 2 || !ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
	{
		ft_printf("Usage: ./fdf <filename>.fdf\n");
		exit(1);
	}
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error: Unable to open file %s\n", argv[1]);
        exit(1);
    }
    close(fd);
	map = initialize_map();
	if (!map)
		exit(1);
	mlx = initialize_mlx();
	if (!mlx)
	{
		free_error_points(map);
		exit(1);
	}
	img = initialize_image(mlx);
	if (!img)
	{
		free_error_points(map);
		mlx_terminate(mlx);
		exit(1);
	}
	draw_stars(img);
	mlx_image_to_window(mlx, img, 0, 0);
    // if (!read_map(map, argv))
    // {
    //     ft_printf("Error: Failed to read map\n");
    //     cleanup(map, img, mlx);
    //     exit(1);
    // }
	smooth_scale(map);
	set_param(map);
	read_map(map, argv);
	calculate_offsets(map, WIN_WIDTH, WIN_HEIGHT);
	map->mlx = img;
	draw_map_array(img, map);
	t_hook_params hook_params;
    hook_params.mlx = mlx; // Assuming mlx is already initialized
    hook_params.img = img; // Assuming img is already initialized
    hook_params.map = map; // Assuming map is already initialized
    mlx_key_hook(mlx, &my_keyhook, &hook_params);
	mlx_loop(mlx);
	cleanup(map, img, mlx);
	return (0);
}

mlx_t	*initialize_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(3840, 2160, "FDF", true);
	if (!mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (NULL);
	}
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
        ft_printf("Error: Failed to initialize map\n");
		exit(1);
	}
	map->matrix = NULL;
	return (map);
}

// valgrind --leak-check=full ./fdf ./test_maps/42.fdf