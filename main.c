/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:16:23 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/25 15:18:50 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(fdf *data);
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color);
void draw_points(mlx_image_t *img, fdf *data);
int parse_map(fdf *data);
//void draw_map_on_image(mlx_t *mlx, mlx_image_t *img, char **argv);

int main(int argc, char **argv)
{
    fdf *data;
	mlx_t *mlx;
	int scale = 20;
	
	
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	mlx = mlx_init(1080, 1080, "Test", true);
	if (!mlx)
        exit(1);

	mlx_image_t* img = mlx_new_image(mlx, 1080, 1080);
	if (!img)
		exit(1);
	data = malloc(sizeof(fdf));
	draw_line(img, 0, 0, 1080, 1080, 0xFFFFFFFF);
	mlx_image_to_window(mlx, img, 0, 0);
	//draw_points(img, data);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	//free_data(data);
	return 0; 
}

// gcc main.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c -I../get_next_line -I../libft -I../MLX42/include -L../MLX42/build -lmlx42 -ldl -lglfw -lX11 -lm -L../libft -lft -o program

// gcc main.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c draw_line.c draw_map.c -I../get_next_line -I../libft -I../MLX42/include -L../MLX42/build -lmlx42 -ldl -lglfw -lX11 -lm -L../libft -lft -o program