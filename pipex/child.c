/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:24:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/27 15:34:10 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*res;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		res = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(res, 0) == 0)
			return (res);
		free(res);
		paths++;
	}
	return (NULL);
}

static void	first_child(t_data *pipex, char **av, char **envp)
{
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	dup2(pipex->infile, 0);
	pipex->args = ft_split(av[2], ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->args[0]);
	if (!pipex->cmd)
	{
		child_free(pipex);
		ft_putstr_fd("Error: Command not found\n", 2);
		exit(1);
	}
	execve(pipex->cmd, pipex->args, envp);
}

static void	second_child(t_data *pipex, char **av, char **envp)
{
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->outfile, 1);
	pipex->args = ft_split(av[4], ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->args[0]);
	if (!pipex->cmd)
	{
		child_free(pipex);
		ft_putstr_fd("Error: Command not found\n", 2);
		exit(1);
	}
	(void) envp;
	execve(pipex->cmd, pipex->args, envp);
}

void	childs(t_data *pipex, char **av, char **envp)
{
	if (!is_justspace(av[2]) && pipex->infile)
	{
		pipex->pid1 = fork();
		if (pipex->pid1 == -1)
			ft_putstr_fd("Error: First child\n", 2);
		if (pipex->pid1 == 0)
			first_child(pipex, av, envp);
	}
	else
		ft_putstr_fd("Error: First command empty\n", 2);
	if (!is_justspace(av[4]) && pipex->outfile)
	{
		pipex->pid2 = fork();
		if (pipex->pid2 == -1)
			ft_putstr_fd("Error: Second child\n", 2);
		if (pipex->pid2 == 0)
			second_child(pipex, av, envp);
	}
	else
		ft_putstr_fd("Error: Second command empty\n", 2);
}