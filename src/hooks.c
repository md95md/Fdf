/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:54:22 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/28 18:05:30 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Function to close the window by pressing the ESC key
void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_hook_params	*hook_params;

	hook_params = (t_hook_params *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		cleanup(hook_params->map, hook_params->img, hook_params->mlx);
		exit(0);
	}
}

void	set_param(t_map *map)
{
	map->param.z_scale = 1.0;
	map->param.shift_x = 0;
	map->param.shift_y = 0;
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
			x++;
		}
		y++;
	}
}

void	cleanup(t_map *map, mlx_image_t *img, mlx_t *mlx)
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

void	fd_check(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		exit(1);
}
