/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:08:26 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/13 13:51:41 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (printf("Error : Couldn't get time\n"), -1);
	return (((tv.tv_sec % 1000) * 1000) + (tv.tv_usec / 1000));
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (++i < n + 1)
		((char *) s)[i - 1] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*res;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	res = malloc(count * size);
	if (res)
	{
		ft_bzero(res, count * size);
		return (res);
	}
	return (NULL);
}

static int	ft_check_overflow(long int n, int last, int sign)
{
	if (sign * n != sign * (n * 10 + last) / 10)
	{
		if (sign * (n * 10 + last) / 10 < 0)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long int	m;
	long int	res;

	res = 0;
	i = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_check_overflow(res, str[i] - 48, m) != 1)
			return (ft_check_overflow(res, str[i] - 48, m));
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	return (res * m);
}
