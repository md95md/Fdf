/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:48:00 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 19:07:52 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./ft_printf_pipex/ft_printf.h"
# include "./libft/libft.h"

char	*find_path(char *cmd, char **envp);
void	ft_free_table(char **tab);
void	simulate_pipe(char *cmd, char **envp);
void	put_error_msg(char *msg);
void	files_err_handler(int argc, int in_fd, int out_fd);

#endif 
