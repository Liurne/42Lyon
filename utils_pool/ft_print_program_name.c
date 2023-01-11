/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:59:00 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/17 17:07:39 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{	
	argc = 0;
	while (argv[0][argc])
	{
		write(1, &argv[0][argc], 1);
		argc++;
	}
	return (0);
}
