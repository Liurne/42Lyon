/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:51:43 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/10 18:46:16 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/minishell.h"

int	main(void)
{
	char	*line;

	printf(YELLOW"=========================\n|"END);
	printf(RED" minishell !! patate ! "END);
	printf(YELLOW"|\n=========================\n"END);
	while (ft_strcmp(line, "exit"))
	{
		if (line)
			free(line);
		line = readline(RED"prout> "END);
	}
	printf(RED"bye bye patate!!\n"END);
	free(line);
	return (0);
}