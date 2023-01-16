/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:12:23 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 16:56:41 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

long int	ft_atol(const char *str);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(long int value);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

#endif