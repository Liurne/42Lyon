/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:25:57 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/14 10:43:17 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		s;

	s = 0;
	while (str[s])
	{
		s++;
	}
	return (s);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{	
	unsigned int	dl;
	unsigned int	sl;
	unsigned int	i;

	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (sl);
	while (i < sl && dl + i < size - 1)
	{
		dest[(dl) + i] = src[i];
		i++;
	}
	dest[(dl) + i] = '\0';
	if (dl > size)
		return (sl + size);
	return (dl + sl);
}
