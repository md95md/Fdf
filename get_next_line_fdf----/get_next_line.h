/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:00:35 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/28 16:03:10 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list2
{
	char			*content;
	struct s_list2	*next;
}	t_list2;

t_list2		*get_last_node(t_list2 *lst);
int			search_for_newline(t_list2 *list);
void		append_node(t_list2 **list, char *buffer_batch);
int			create_list(t_list2 **list, int fd);
size_t		len_till_nl(t_list2	*start_node);
char		*get_next_line(int fd);
void		keep_rest(t_list2 **list);
void		free_list(t_list2 **list, t_list2 *clean_node, char *buffer);
char		*retrive_line(t_list2	*list);
int			fill_line_from_content(char *line, int *i, char *content);

#endif
