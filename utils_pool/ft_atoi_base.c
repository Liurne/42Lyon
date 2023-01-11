/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:15:07 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/27 11:48:09 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    ft_strlen(char *str)
{
    int    s;

    s = 0;
    while (str[s])
    {
        s++;
    }
    return (s);
}

int    is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int    is_base_ok(char *str, int size)
{
    int    i;
    int    j;

    i = 0;
    if (str[0] == '-' || str[0] == '+' || size <= 1 || is_space(str[0]))
        return (0);
    while (str[i])
    {
        j = i + 1;
        while (j < size)
        {
            if (str[j] == str[i] || str[j] == '-'
                || str[j] == '+' || is_space(str[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int    get_int(char c, char *b)
{
    int    i;

    i = 0;
    while (b[i])
    {
        if (c != b[i])
            i++;
        else
            return (i);
    }
    return (-1);
}

int    ft_atoi_base(char *str, char *base)
{
    int    number;
    int    b_l;
    int    s_l;
    int    i;
    int    pos;

    pos = 1;
    b_l = ft_strlen(base);
    s_l = ft_strlen(str);
    i = 0;
    number = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            pos *= -1;
        i++;
    }
    while (get_int(str[i], base) >= 0 && is_base_ok(base, b_l))
    {
        number = number * b_l + get_int(str[i], base);
        i++;
    }
    return (pos * number);
}
