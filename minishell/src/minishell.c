/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:20:04 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/11 18:24:38 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pars(t_data *prmt)
{
	int	i;

	prmt->cmd = ft_split_space(&(prmt->line));
	if (!prmt->cmd)
		return (0);
	i = -1;
	while (prmt->cmd[++i][0])
		printf("%s\n", prmt->cmd[i]);
	return (1);
}