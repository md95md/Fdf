/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:13 by agaleeva          #+#    #+#             */
/*   Updated: 2024/03/09 18:03:00 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_word(char const *s, char c, size_t *i)
{
	char	*word;
	size_t	begin;

	begin = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	begin = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = ft_substr(s, begin, *i - begin);
	return (word);
}

static void	ft_free_split(char **arr, size_t size)
{
	while (size > 0)
	{
		size--;
		free(arr[size]);
	}
	free(arr);
}

static char	**split_words(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[j] = ft_word(s, c, &i);
			if (!arr[j])
			{
				ft_free_split(arr, j);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = split_words(s, c, arr);
	if (!arr)
		return (NULL);
	return (arr);
}
