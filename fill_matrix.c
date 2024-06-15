/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:20:07 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/15 19:02:32 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define true 1

int	count_lines(char **argv)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

void	free_data(fdf *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->mlx)
	{
		mlx_terminate(data->mlx);
	}
	free(data);
}

static void	error(fdf *data)
{
	free_data(data);
	exit(1);
}

int	get_map(fdf *data, char **argv)
{
	int		lines;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free_data(data);
		exit(1);
	}
	lines = count_lines(argv);
	data->map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data->map)
		error(data);
	i = 0;
	while (i < lines)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}

int fill_matrix(fdf *data)
{
	// Add your code here
}

void display_map(fdf *data, mlx_t *mlx)
{
	// Add your code here
}

int32_t main(int argc, char **argv)
{
	fdf *data;
	mlx_t *mlx;
	
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	if (get_map(data, argv) != 0)
	{
		printf("Failed to read map\n");
		free_data(data);
		return 1;
	}
	fill_matrix(data);
	mlx = mlx_init(2560, 1440, "FDF", &data->mlx);
	// Display the map on the window
	bresenham(0, 0, 100, 100, data);
	display_map(data, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_data(data);
	return 0;
}

//gcc fill_matrix.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c -I../get_next_line -I../libft -I../MLX42/include -L../MLX42/build -lmlx42 -ldl -lglfw -lX11 -lm -L../libft -lft -o fill_matrix