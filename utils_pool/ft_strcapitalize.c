/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:37:20 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/10 17:26:59 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char c)
{
	int	t;

	t = 0;
	if (c >= 'a' && c <= 'z')
		t = 1;
	if (c >= 'A' && c <= 'Z')
		t = 1;
	if (c >= '0' && c <= '9')
		t = 1;
	return (t);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = 'A' + (str[0] - 'a');
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && ft_isalnum(str[i - 1]) == 0)
			str[i] = 'A' + (str[i] - 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z' && ft_isalnum(str[i - 1]) == 1)
			str[i] = 'a' + (str[i] - 'A');
		i++;
	}
	return (str);
}
