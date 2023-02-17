/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:43:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 17:17:53 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
	size_t			content;
	struct s_list	*next;
}	t_list;

/* -----libft----- */
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *s, int fd);
int			ft_isnumber(char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c, size_t *nbV);
void		*ft_free(char **tab, size_t nbword);
char		*ft_strjoin(char const *s1, char const *s2);
long int	ft_atol(const char *str);
long int	*ft_split_atoi(char const *s, char c, size_t *nbV);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(long int value);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstbeforelast(t_list *lst);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		**ft_lstinit(void);

/* -----parsing----- */
long int	*ft_split_spe(char const *s, size_t *n);
int			ft_load(t_list **lst, int ac, char **av);
int			ft_error(t_list **a, t_list **b);
int			ft_isdouble(long int *tab, size_t index, size_t size);

#endif