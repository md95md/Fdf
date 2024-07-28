/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:37:52 by sliashko          #+#    #+#             */
/*   Updated: 2024/07/28 16:44:02 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char			*content;
	struct s_gnl	*next;
}	t_gnl;

t_gnl		*get_last_node(t_gnl *lst);
int			search_for_newline(t_gnl *list);
void		append_node(t_gnl **list, char *buffer_batch);
int			create_list(t_gnl **list, int fd);
size_t		len_till_nl(t_gnl	*start_node);
char		*get_next_line(int fd);
void		keep_rest(t_gnl **list);
void		free_list(t_gnl **list, t_gnl *clean_node, char *buffer);
char		*retrive_line(t_gnl	*list);
int			fill_line_from_content(char *line, int *i, char *content);

# endif
