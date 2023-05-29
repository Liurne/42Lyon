/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:51:43 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/11 18:25:47 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/minishell.h"

int	main(void)
{
	t_data	prompt;

	ft_bzero(&prompt, sizeof(t_data));
	printf(YELLOW"===========================\n||"END);
	printf(RED" minishell !! patate ! "END);
	printf(YELLOW"||\n===========================\n"END);
	while (ft_strcmp(prompt.line, "exit"))
	{
		if (prompt.line)
			free(prompt.line);
		prompt.line = readline(RED"patate> "END);
		ft_pars(&prompt);
	}
	printf(RED"bye bye patate!!\n"END);
	free(prompt.line);
	return (0);
}