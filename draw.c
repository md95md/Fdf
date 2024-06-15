/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:43:14 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/15 19:17:17 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float mod(float i)
{
    if (i < 0)
        return (-i);
    return (i);
}

int max_value(float a, float b)
{
    if (a > b)
        return (a);
    return (b);
}

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
    mlx_image_t *image;
    float x_step;
    float y_step;
    int max;

    x_step = x1 - x;
    y_step = y1 - y;
    max = max_value(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_put_pixel(image, x, y, 0x00FF00);
        x += x_step;
        y += y_step;
    } 
}

