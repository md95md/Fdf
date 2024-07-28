/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:27:57 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/28 16:09:13 by agaleeva         ###   ########.fr       */
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
				if (map->matrix[i])
				{
					free(map->matrix[i]);
					map->matrix[i] = NULL;
				}
				i++;
			}
			free(map->matrix);
			map->matrix = NULL;
		}
	}
}

int	get_map_size(t_map *map, char **argv)
{
	if (get_width(argv) == 0)
		return (0);
	map->width = get_width(argv);
	if (get_height(argv) == 0)
		return (0);
	map->height = get_height(argv);
	return (1);
}

int	read_map_help(t_map *map, char **argv)
{
	int	i;

	i = 0;
	if (get_map_size(map, argv) == 0)
		return (0);
	get_map_size(map, argv);
	map->matrix = (t_point **)malloc(map->height * sizeof(t_point *));
	if (!map->matrix)
		free_error_points(map);
	while (i < map->height)
	{
		map->matrix[i] = (t_point *)malloc(map->width * sizeof(t_point));
		if (!map->matrix[i])
			free_error_points(map);
		i++;
	}
	return (1);
}

int	read_map(t_map *map, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (get_map_size(map, argv) == 0)
		return (0);
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
	return (1);
}

// void	read_map(t_map *map, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	get_map_size(map, argv);
// 	read_map_help(map, argv);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		free_error_points(map);
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		fill_matrix(map->matrix[i], line, i, map);
// 		free(line);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }
