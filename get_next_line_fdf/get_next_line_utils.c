/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:42:49 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/31 11:42:52 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//This function extracts the last node from linked list
t_list2	*get_last_node(t_list2 *lst)
{
	t_list2	*curr_node;

	if (lst == NULL)
		return (NULL);
	curr_node = lst;
	while (curr_node->next != NULL)
	{
		curr_node = curr_node->next;
	}
	return (curr_node);
}

//Goes over content of nodes untill it meets new line
int	search_for_newline(t_list2 *list)
{
	t_list2	*curr_node;
	char	*curr_content;

	curr_node = list;
	while (curr_node != NULL)
	{
		curr_content = curr_node->content;
		while (*curr_content != '\0')
		{
			if (*curr_content == '\n')
				return (1);
			curr_content++;
		}
		curr_node = curr_node->next;
	}
	return (0);
}

//Adding new node to the end of linked list
void	append_node(t_list2 **list, char *buffer_batch)
{
	t_list2	*last_node;
	t_list2	*new_node;

	last_node = get_last_node(*list);
	new_node = (t_list2 *) malloc(sizeof(t_list2));
	if (new_node == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
	}
	else
		last_node->next = new_node;
	new_node->content = buffer_batch;
	new_node->next = NULL;
}

// Reads chunks untill it faces 1st newline within chunks
// returns status of reading
int	create_list(t_list2 **list, int fd)
{
	char	*buffer;
	int		char_read;

	while (search_for_newline(*list) == 0)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (-1);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buffer);
			return (-1);
		}
		if (char_read == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[char_read] = '\0';
		append_node(list, buffer);
	}
	return (1);
}

//Counts num of chars in content untill first new line 
//We need this amount for allocating memory
size_t	len_till_nl(t_list2	*start_node)
{
	size_t	len;
	t_list2	*curr_node;
	char	*curr_content;

	len = 0;
	curr_node = start_node;
	while (curr_node != NULL)
	{
		curr_content = curr_node->content;
		while (*curr_content != '\0')
		{
			if (*curr_content == '\n')
				return (len);
			curr_content++;
			len++;
		}
		curr_node = curr_node->next;
	}
	return (len);
}
