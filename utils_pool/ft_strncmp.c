/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:40:10 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/14 13:38:51 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if ((s1[i] > s2[i] || s1[i] < s2[i]) && n != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] > s2[i] || s1[i] < s2[i]) && n != 0)
		return (s1[i] - s2[i]);
	return (0);
}
