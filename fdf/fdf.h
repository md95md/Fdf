/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:05:50 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/07 14:32:27 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define EXIT_FAILURE 1
# define WIN_WIDTH 3600
# define WIN_HEIGHT 1800

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
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
	t_point		**matrix;
	t_point		*points;
	int			height;
	int			width;
	void		*mlx;
	void		*win;
	uint32_t	color;
	t_param		param;
}	t_map;

void	draw_line(t_point p0, t_point p1, t_map *map);
int		get_height(char **argv);
int		get_width(char **argv);
void	read_map(t_map *map, char **argv);
void	draw_map_array(mlx_image_t *img, t_map *map);
void	isometric_projection(t_point *point);
void	free_error_points(t_map *map);
void	fill_matrix(t_point *points, char *line, int y, t_map *map);
void	free_error_points(t_map *map);
void	calculate_offsets(t_map *map, float win_width, float win_height);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	smooth_scale(t_map *map);
void	draw_stars(mlx_image_t *img);
void	shift_p1(t_point *p1, t_map *map);
void	shift_p0(t_point *p0, t_map *map);

#endif