/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:06:54 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/27 15:39:52 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *error, t_data *pipex)
{
	if (pipex->is_pipe_open == 0)
		close_pipes(pipex);
	ft_putstr_fd(error, 2);
	exit (1);
}

int	is_justspace(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != ' ' && !(*str >= 9 && *str <= 13))
			return (0);
		str++;
	}
	return (1);
}

void	close_pipes(t_data *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	parent_free(t_data *pipex)
{
	int	i;

	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	i = 0;
	if (pipex->infile)
		close(pipex->infile);
	if (pipex->outfile)
		close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child_free(t_data *pipex)
{
	int	i;

	i = 0;
	while (pipex->args[i])
	{
		free(pipex->args[i]);
		i++;
	}
	free(pipex->args);
	free(pipex->cmd);
}