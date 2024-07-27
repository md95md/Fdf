/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:54:22 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/27 18:35:55 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Function to close the window by pressing the ESC key

// static int	close_window(t_map *vars)
// {
// 	//if (vars->img_data.img != NULL)
// 		//mlx_destroy_image(vars->mlx, vars->img_data.img);
// 		//mlx_terminate(vars->mlx);
// 	//mlx_destroy_window(vars->mlx, vars->win);
// 	mlx_terminate(vars->mlx);
// 	//mlx_destroy_display(vars->mlx);
// 	free(vars->mlx);
// 	exit(0);
// 	return (0);
// }

// int	key_press(int keycode, t_map *vars)
// {
// 	if (keycode == MLX_KEY_ESCAPE && keycode == MLX_RELEASE)
// 		close_window(vars);
// 	return (0);
// }

void		my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		free_error_points(map);
		exit(0);
	}
	free(map);
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
			// if (rand() % 2000 == 0)
			// 	mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}
