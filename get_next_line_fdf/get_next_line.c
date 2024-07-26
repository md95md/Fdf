/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:47:13 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/25 15:55:13 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char	*set_line(char *line_buffer);
static char	*fill_line_buffer(int fd, char *prev_c, char *buffer);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		subs = (char *)malloc(1 * sizeof(char));
		subs[0] = 0;
		return (subs);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (subs == 0)
		return (NULL);
	while (*s && len--)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*get_next_line(int fd)
{
	static char	*prev_c;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, prev_c, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	prev_c = set_line(line);
	return (line);
}

static char	*fill_line_buffer(int fd, char *prev_c, char *buffer)

{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			break ;
		else if (bytes_read < 0)
		{
			free (prev_c);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		if (!prev_c)
			prev_c = ft_strdup("");
		temp = prev_c;
		prev_c = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(prev_c, '\n'))
			break ;
	}
	return (prev_c);
}

static char	*set_line(char *line_buffer)
{
	char		*prev_c;
	size_t		i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	prev_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (prev_c == NULL)
		return (NULL);
	if (*prev_c == 0)
	{
		free(prev_c);
		prev_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (prev_c);
}
