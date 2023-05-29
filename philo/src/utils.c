/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:32:47 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 16:15:06 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_bzero(void *s, long int n)
{
		long int	i;

		i = 0;
		while (++i < n + 1)
			((char *) s)[i - 1] = '\0';
}

int	ft_atoi(const char *str)
{
		long int	i;
		long int	m;
		long int	res;

		res = 0;
		i = 0;
		m = 1;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
				i++;
		if (str[i] == '-')
				m = -1;
		if (str[i] == '+' || str[i] == '-')
				i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
				res = (res * 10) + (str[i] - '0');
				i++;
		}
		return (res * m);
}

long int	get_time()
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error : couldn't get time\n");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));	
}