/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:39:13 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/15 19:17:05 by agaleeva         ###   ########.fr       */
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
#include "..//MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_data
{
    int width;
    int height;
    int **z_matrix;

    void *mlx_ptr;
    void *win_ptr;
    char **map;
    mlx_t *mlx;
    mlx_image_t *image;
} fdf;

void bresenham(float x, float y, float x1, float y1, fdf *data);


#endif
