/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:27:57 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/05 17:09:52 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_error_points(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->matrix)
		{
			i = 0;
			while (i < map->height)
			{
				free(map->matrix[i]);
				i++;
			}
			free(map->matrix);
		}
		free(map);
	}
	exit(EXIT_FAILURE);
}

void	get_map_size(t_map *map, char **argv)
{
	map->width = get_width(argv);
	map->height = get_height(argv);
	map->matrix = (t_point **)malloc(map->height * sizeof(t_point *));
	if (!map->matrix)
		free_error_points(map);
}

void	read_map_help(t_map *map, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	get_map_size(map, argv);
	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = (t_point *)malloc(map->width * sizeof(t_point));
		if (!map->matrix[i])
			free_error_points(map);
		i++;
	}
}

void	read_map(t_map *map, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	get_map_size(map, argv);
	read_map_help(map, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		free_error_points(map);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(map->matrix[i], line, i, map);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
