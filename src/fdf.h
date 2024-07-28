/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:05:50 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/28 15:28:07 by agaleeva         ###   ########.fr       */
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
# include <fcntl.h>
# include "../MLX42_fdf/include/MLX42/MLX42.h"
# include "../get_next_line_fdf/get_next_line.h"
# include "../ft_printf_fdf/ft_printf.h"
# include "../libft/libft.h"
# include <errno.h>
# include <limits.h>

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
	void	*img;
}	t_param;

typedef struct s_map
{
	t_point		**matrix;
	t_point		*points;
	int			height;
	int			width;
	void		*mlx;
	void		*win;
	void		*img;
	t_param		img_data;
	uint32_t	color;
	t_param		param;
}	t_map;

typedef struct s_hook_params
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
}	t_hook_params;

void		draw_line(t_point p0, t_point p1, t_map *map);
int			get_height(char **argv);
int			get_width(char **argv);
int		read_map(t_map *map, char **argv);
//int read_map(t_map *map, char **argv);
void		draw_map_array(mlx_image_t *img, t_map *map);
void		isometric_projection(t_point *point);
void		free_error_points(t_map *map);
void		fill_matrix(t_point *points, char *line, int y, t_map *map);
void		calculate_offsets(t_map *map, float win_width, float win_height);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		smooth_scale(t_map *map);
void		draw_stars(mlx_image_t *img);
void		draw_horizontal_lines(mlx_image_t *img, t_map *map, int y);
void		draw_vertical_lines(mlx_image_t *img, t_map *map, int x);
void		apply_projections_and_shift(t_point *p, t_map *map);
void		shift_point(t_point *p, t_map *map);
void		set_param(t_map *map);
void		free_map(t_map *map);
void		free_1(t_map *map);
void		cleanup(t_map *map, mlx_image_t *img, mlx_t *mlx);
mlx_t		*initialize_mlx(void);
mlx_image_t	*initialize_image(mlx_t *mlx);
t_map		*initialize_map(void);
int			key_press(int keycode, t_map *vars);
#endif