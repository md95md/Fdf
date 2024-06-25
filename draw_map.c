/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:04:30 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/25 15:27:19 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int parse_map(fdf *data)
{
    int i;
    int j;
    char **split;

    i = 0;
    while (data->map[i] != NULL)
    {
        j = 0;
        split = ft_split(data->map[i], ' ');
        while (split[j] != NULL)
        {
            data->map[i][j] = ft_atoi(split[j]);
            j++;
        }
        i++;
    }
    return (0);
}

void draw_points(mlx_image_t *img, fdf *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i] != NULL)
    {
        j = 0;
        while (data->map[i][j] != '\0')
        {
            mlx_put_pixel(img, j, i, 0xFFFFFF);
            j++;
        }
        i++;
    }
}

#include <stdlib.h>

typedef struct s_fdf {
    char **map;
    void *mlx_ptr;
    void *win_ptr;
} fdf;

// Assume get_map is defined as shown previously

void draw_map(fdf *data) {
    int x, y;
    y = 0;
    while (data->map[y]) {
        x = 0;
        while (data->map[y][x]) {
            if (data->map[y][x] == '1') { // Assuming '1' represents a wall
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, x * 10, y * 10, 0xFFFFFF); // Draw a white pixel (or square) for each wall
            }
            x++;
        }
        y++;
    }
}

int main(int argc, char **argv) {
    fdf data;

    if (argc != 2) {
        write(2, "Usage: ./get_map <map_file>\n", 28);
        return (1);
    }

    get_map(&data, argv); // Load the map

    data.mlx_ptr = mlx_init(1080, 1080, "Test", true);
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Map Window");
    if (data.win_ptr == NULL)
        return (1);

    draw_map(&data); // Draw the map

    mlx_loop(data.mlx_ptr); // Enter the MLX event loop
    return (0);
}

//gcc draw_map.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c draw_line.c -I../get_next_line -I../libft -I../MLX42/include -L../MLX42/build -lmlx42 -ldl -lglfw -lX11 -lm -L../libft -lft -o program