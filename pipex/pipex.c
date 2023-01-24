/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:19 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/24 14:17:54 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	char	**paths;
	char	**cmd;
	char	*cmd_paths;
	if (ac != 5)
		return (1);
	paths = ft_split(find_path(envp), ':');
	cmd = ft_split(av[2],' ');
	cmd_paths = get_cmd(paths, cmd[0]);
	execve(cmd_paths, cmd, envp);
	return (0);
}