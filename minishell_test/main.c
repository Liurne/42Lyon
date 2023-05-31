/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:51:43 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/31 16:50:20 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/minishell.h"

int	main(int ac, char** av, char **envp)
{
	t_data	prompt;

	(void)ac;
	(void)av;
	if (!envp || !envp[0] || !ft_strncmp("PATH", *envp, 4))
		return (printf("Error: environment non existent\n"), 1);
	ft_bzero(&prompt, sizeof(t_data));
	printf(YELLOW"===========================\n||"END);
	printf(RED" minishell !! patate ! "END);
	printf(YELLOW"||\n===========================\n"END);
	while (ft_strcmp(prompt.line, "exit"))
	{
		if (prompt.line)
			free(prompt.line);
		prompt.line = readline(RED"patate> "END);
		if (prompt.line[0])
			add_history(prompt.line);
		if (!ft_strcmp(prompt.line, "pwd"))
			printf("%s\n",getcwd(NULL, 0));
	}
	printf(RED"bye bye patate!!\n"END);
	free(prompt.line);
	return (0);
}