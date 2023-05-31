/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:58:59 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/31 16:07:26 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*append_str(char *s1, char *s2)
{
	char *res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	if (!res)
		return (NULL);
	s1 = res;
	return (res);
	
}

static char	*get_arg(const char *str, va_list ap)
{
	if (*str == 'c')
		return (get_char((char)va_arg(ap, int)));
	if (*str == '%')
		return (get_char('%'));
	if (*str == 's')
		return (va_arg(ap, char *));
	if (*str == 'i' || *str == 'd')
		return (ft_itoa(va_arg(ap, int)));
	if (*str == 'x')
		return (get_hexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (*str == 'X')
		return (get_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (*str == 'u')
		return (ft_itoa(va_arg(ap, unsigned int)));
	return (0);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	long int	i;
	char		*res;

	i = -1;
	if (!str)
		return (0);
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%' && *(str + i + 1))
		{
			res = append_str(res, ft_strndup(str, i));
			str += i + 1;
			i = -1;
			append_str(res, get_arg(str, ap));
		}
	}
	if (!append_str(res, ft_strndup(str, i)))
		return (va_end(ap), -1);
	i = write(fd, res, ft_strlen(res));
	va_end(ap);
	return (free(res), (int)i);
}
