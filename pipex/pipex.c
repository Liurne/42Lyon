/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:19 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/24 13:50:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int ac, char **av, char **envp)
{
	t_data	pipex;

	if (ac != 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2));
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error("Infile", &pipex);
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		msg_error("Outfile", &pipex);
	pipex.is_pipe_open = pipe(pipex.pipe);
	if (pipex.is_pipe_open < 0)
		msg_error("Pipe", &pipex);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(find_path(envp), ':');
	childs(&pipex, av, envp);
	return (parent_free(&pipex), 0);
}