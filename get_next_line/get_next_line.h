/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:08:26 by agaleeva          #+#    #+#             */
/*   Updated: 2024/06/26 15:18:27 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

//size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
//char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_strchr(const char *s, int c);
//char	*ft_strdup(const char *s);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
void	fill_str(char *res, char const *s1, char const *s2);

#endif