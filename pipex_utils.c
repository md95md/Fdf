/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:52:46 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 19:07:47 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	retrieve_path_dirs(char **envp, char ***arr_dirs)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			*arr_dirs = ft_split(envp[i] + 5, ':');
			return ;
		}
		i++;
	}
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**path_dirs;
	char	*exec_file;

	retrieve_path_dirs(envp, &path_dirs);
	i = 0;
	while (path_dirs[i] != NULL)
	{
		exec_file = ft_strjoin(path_dirs[i], "/");
		exec_file = ft_strjoin(exec_file, cmd);
		if (access(exec_file, F_OK | X_OK) != -1)
		{
			free(path_dirs);
			return (exec_file);
		}
		i++;
	}
	return (NULL);
}

void	ft_free_table(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	put_error_msg(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

void	files_err_handler(int argc, int in_fd, int out_fd)
{
	if (argc < 5)
		put_error_msg("Too few args\n");
	if (in_fd == -1)
		put_error_msg("Cannot access input file\n");
	if (out_fd == -1)
		put_error_msg("Cannot access output file\n");
}
