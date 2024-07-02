/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:05:50 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/02 16:06:24 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define EXIT_FAILURE 1

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_param
{
	float	scale;
	float	z_scale;
	int		is_isometric;
	float	angle;
	float	shift_x;
	float	shift_y;
}	t_param;

typedef struct s_map
{
	int			**matrix;
	t_point		*points;
	int			height;
	int			width;
	void		*mlx;
	void		*win;
	uint32_t	color;
}	t_map;

void	draw_line(float x, float y, float x1, float y1, t_map *map);
//void	draw_line(t_point *p0, float x1, float y1, t_map *map);
void	draw_map_array(mlx_image_t *img, t_map *map);
int		get_height(char **argv);
int		get_width(char **argv);
void	read_map(t_map *map, char **argv);
void	draw_dots(mlx_image_t *img, t_map *matrix, uint32_t color);
void	get_map(t_map *map, char **argv);
void	draw_map_array(mlx_image_t *img, t_map *map);
void	isometric(float *x, float *y, int z);
//void	isometric(t_point *dot, float angle);
void	free_error_points(t_map *map);
void	fill_matrix(int *z_line, char *line);
void	free_error_points(t_map *map);

// typedef struct s_dline
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;
// }	t_dline;

// typedef struct s_dpoints
// {
// 	int	x0;
// 	int	y0;
// 	int	x1;
// 	int	y1;
// }	t_dpoints;

//void	isometric(float *x, float *y, int z);

#endif