/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:13:00 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/31 15:53:57 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_char(char c)
{
	char *res;

	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return(NULL);
	res[0] = c;
	res[1] ='\0';
	return (res);
}

unsigned int	rec_hexa(unsigned int nb)
{
	unsigned int	len;
	
	len = 0;
	if (nb > 15)
	{
		len += rec_hexa(nb / 16);
		len += rec_hexa(nb % 16);
	}
	else
		len++;
	return(len);
}

void fill_hexa(unsigned int nb, char *base, char *res)
{
	if (nb > 15)
	{
		fill_hexa(nb / 16, base, res++);
		fill_hexa(nb % 16, base, res++);
	}
	else
		*res = base[nb % 16];
}

char	*get_hexa(unsigned int nb, char *base)
{
	unsigned int	len;
	char			*res;

	len = rec_hexa(nb);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	fill_hexa(nb, base, res);
	return (res);
}