/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:56:06 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/28 15:46:48 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int is_digit_string(char *str)
{
    while (*str)
    {
        while (*str == ' ')
            str++;
        if (*str == '\0' || *str == '\n')
            break;
        if (*str == '-')
        {
            str++;
            if (*str < '0' || *str > '9')
                return 0;
        }
        else if (*str < '0' || *str > '9')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int	get_width(char **argv)
{
	int		fd;
	int		width;
	char	*line;
	char	**split_line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		exit(-1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	if (!is_digit_string(line))
	{
		free(line);
		close(fd);
		return (0);
	}
	split_line = ft_split(line, ' ');
	free(line);
	close(fd);
	width = 0;
	while (split_line[width])
	{
		free(split_line[width]);
		width++;
	}
	free(split_line);
	return (width);
}

int	get_height(char **argv)
{
	int		fd;
	int		height;
	char	*line;
	height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_digit_string(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	fill_matrix(t_point *points, char *line, int y, t_map *map)
{
	char	**numbers;
	int		i;
	numbers = ft_split(line, ' ');
	i = 0;
	while (numbers[i])
	{
		points[i].x = i * map->param.scale;
		points[i].y = y * map->param.scale;
		points[i].z = ft_atoi(numbers[i]) * map->param.z_scale;
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

// int	get_width(char **argv)
// {
// 	int		fd;
// 	int		width;
// 	char	*line;
// 	char	**split_line;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1 || read(fd, NULL, 0) == -1)
// 		exit(-1);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (0);
// 	if (!is_digit_string(line))
// 	{
// 		printf("Error: Invalid map\n");
// 		free(line);
// 		close(fd);
// 		exit (1);
// 	}
// 	split_line = ft_split(line, ' ');
// 	free(line);
// 	close(fd);
// 	width = 0;
// 	while (split_line[width])
// 	{
// 		free(split_line[width]);
// 		width++;
// 	}
// 	free(split_line);
// 	return (width);
// }

// int	get_height(char **argv)
// {
// 	int		fd;
// 	int		height;
// 	char	*line;

// 	height = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		height++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (height);
// }

// void	fill_matrix(t_point *points, char *line, int y, t_map *map)
// {
// 	char	**numbers;
// 	int		i;

// 	numbers = ft_split(line, ' ');
// 	i = 0;
// 	while (numbers[i])
// 	{
// 		points[i].x = i * map->param.scale;
// 		points[i].y = y * map->param.scale;
// 		points[i].z = ft_atoi(numbers[i]) * map->param.z_scale;
// 		free(numbers[i]);
// 		i++;
// 	}
// 	free(numbers);
// }

/*
int main(int argc, char **argv)
{
    t_map *map;

    if (argc != 2)
    {
        printf("Usage: ./fdf <filename>\n");
        return (1);
    }
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (1);
    read_map(map, argv);

    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            printf("%3d ", map->matrix[i][j]);
        }
        printf("\n");
    }
    free_error_points(map);
    return (0);
}
*/