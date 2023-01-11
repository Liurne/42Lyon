/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:19 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/10 14:59:28 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	t;
	unsigned int	n;

	t = 0;
	n = 0;
	if (size != 0)
	{
		while (src[t] != '\0')
		{
			if (t < (size - 1))
			{
				dest[t] = src[t];
				n++;
			}
			t++;
		}
	}
	else
	{
		while (src[t] != '\0')
			t++;
		return (t);
	}
	dest[n] = '\0';
	return (t);
}
