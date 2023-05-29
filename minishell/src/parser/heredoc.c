/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:42:21 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/11 17:15:57 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_hd(char *line)
{
	size_t	i;
	char	*end;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	end = ft_strndup(line, i);
	printf("%s\n", end);
	return (1);
}

int is_hd(char *line)
{
	char	*tmp;
	

	tmp = ft_strstr(line, "<<");
	if (!tmp)
		return (0);
	printf("%s\n", tmp);
	
	
	return (1);
}
