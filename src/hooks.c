/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:54:22 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/27 18:59:44 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Function to close the window by pressing the ESC key
void my_keyhook(mlx_key_data_t keydata, void *param)
{
    t_hook_params *hook_params = (t_hook_params *)param;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
    {
        mlx_loop(hook_params->mlx);
        cleanup(hook_params->map, hook_params->img, hook_params->mlx);
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
			// if (rand() % 2000 == 0)
			// 	mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}
