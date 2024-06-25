/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:39:49 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/25 13:16:21 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

//gcc get_map.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c -I../get_next_line -I../libft -I../MLX42/include -L../MLX42/build -lmlx42 -ldl -lglfw -lX11 -lm -L../libft -lft -o get_map