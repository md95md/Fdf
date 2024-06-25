/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:36:37 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/25 15:14:04 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_data
{
    int width;
    int height;
    int **z_matrix;
    float x;
    float y;
    float z;
    int is_last;
    int win_x;
    int win_y;

    void *mlx_ptr;
    void *win_ptr;
    char **map;
    mlx_t *mlx;
    mlx_image_t *image;
} fdf;


void	error(fdf *data);
void	free_data(fdf *data);
int	count_lines(char **argv);
int	get_map(fdf *data, char **argv);
//void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color);


# endif
