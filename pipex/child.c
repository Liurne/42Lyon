/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:24:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/24 15:11:26 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_everything(t_data *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	close(pipex->outfile);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*res;

	if (!access(cmd, X_OK))
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		res = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(res, X_OK) == 0)
			return (res);
		free(res);
		paths++;
	}
	return (NULL);
}

static void	first_child(t_data *pipex, char **av, char **envp)
{
	if (dup2(pipex->pipe[1], 1) == -1 || dup2(pipex->infile, 0) == -1)
		ft_putstr_fd("Error: dup2 1 didn't work\n", 2);
	else
	{
		pipex->args = ft_split(av[2], ' ');
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->args[0]);
		if (!pipex->cmd)
		{
			child_free(pipex);
			ft_putstr_fd("Error: Command \"", 2);
			ft_putstr_fd(av[2], 2);
			ft_putstr_fd("\" not found\n", 2);
			exit(1);
		}
		close_everything(pipex);
		if (execve(pipex->cmd, pipex->args, envp) == -1)
		{
			ft_putstr_fd("Error: execve first child\n", 2);
			child_free(pipex);
			exit(1);
		}
	}
	close_everything(pipex);
	exit(1);
}

static void	second_child(t_data *pipex, char **av, char **envp)
{
	if (dup2(pipex->pipe[0], 0) == -1 || dup2(pipex->outfile, 1) == -1)
		ft_putstr_fd("Error: dup2 2 didn't work\n", 2);
	else
	{
		pipex->args = ft_split(av[3], ' ');
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->args[0]);
		if (!pipex->cmd)
		{
			child_free(pipex);
			ft_putstr_fd("Error: Command \"", 2);
			ft_putstr_fd(av[3], 2);
			ft_putstr_fd("\" not found\n", 2);
			exit(1);
		}
		close_everything(pipex);
		if (execve(pipex->cmd, pipex->args, envp) == -1)
		{
			ft_putstr_fd("Error: execve second child\n", 2);
			child_free(pipex);
			exit(1);
		}
	}
	close_everything(pipex);
	exit(1);
}

void	childs(t_data *pipex, char **av, char **envp)
{
	if (pipex->infile > 0 && !is_justspace(av[2]))
	{
		pipex->pid1 = fork();
		if (pipex->pid1 == -1)
			ft_putstr_fd("Error: First child\n", 2);
		if (pipex->pid1 == 0)
			first_child(pipex, av, envp);
	}
	if (is_justspace(av[2]))
		ft_putstr_fd("Error: First command empty\n", 2);
	if (pipex->outfile > 0 && !is_justspace(av[3]))
	{
		pipex->pid2 = fork();
		if (pipex->pid2 == -1)
			ft_putstr_fd("Error: Second child\n", 2);
		if (pipex->pid2 == 0)
			second_child(pipex, av, envp);
	}
	if (is_justspace(av[3]))
		ft_putstr_fd("Error: Second command empty\n", 2);
}
