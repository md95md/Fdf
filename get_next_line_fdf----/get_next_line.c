/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:01:09 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/28 16:02:02 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//This is sub-routine function for retrieve line
// I moved it out because of Norminette
int	fill_line_from_content(char *line, int *i, char *content)
{
	int	j;

	j = 0;
	while (content[j] != '\0')
	{
		line[*i] = content[j];
		if (content[j] == '\n')
		{
			line[*i + 1] = '\0';
			return (1);
		}
		(*i)++;
		j++;
	}
	return (0);
}

//Creates an array and copies there charachers till new line
char	*retrive_line(t_list2	*list)
{
	char	*line;
	int		i;

	line = (char *) malloc(sizeof(char) * (len_till_nl(list) + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (list != NULL)
	{
		if (fill_line_from_content(line, &i, list->content))
			return (line);
		list = list->next;
	}
	line[i] = '\0';
	return (line);
}

//Cleans all the allocated blocks of memory in linked list
void	free_list(t_list2 **list, t_list2 *clean_node, char *buffer)
{
	t_list2	*temp_node;

	if (*list == NULL)
		return ;
	while (*list)
	{
		temp_node = (*list)->next;
		free((*list)->content);
		free((*list));
		*list = temp_node;
	}
	*list = NULL;
	if (*buffer != '\0' || clean_node == NULL)
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}

//Keeps the remaining part of the read chunk after new line
//to work with it on next iteration
void	keep_rest(t_list2 **list)
{
	t_list2	*clean_node;
	t_list2	*last_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_node = malloc(sizeof(t_list2));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = get_last_node(*list);
	i = 0;
	j = 0;
	if (last_node == NULL || last_node->content == NULL)
		return ;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content[i] == '\n')
		i++;
	while (last_node->content[i] != '\0')
		buffer[j++] = last_node->content[i++];
	buffer[j] = '\0';
	clean_node->content = buffer;
	clean_node->next = NULL;
	free_list(list, clean_node, buffer);
}

//Our main function itself
char	*get_next_line(int fd)
{
	static t_list2	*list;
	char			*next_line;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free_list(&list, NULL, "");
		return (NULL);
	}
	status = create_list(&list, fd);
	if (status == -1)
	{
		free_list(&list, NULL, "");
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
	next_line = retrive_line(list);
	keep_rest(&list);
	return (next_line);
}
