/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:43:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/17 14:52:41 by jcoquard         ###   ########.fr       */
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
	int				content;
	struct s_list	*next;
}	t_list;

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *s);
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
void		ft_afflst(t_list **lst);
t_list		**ft_lstinit(void);

long int	*ft_load(int nbA, char **val, size_t *nbV);
t_list		**ft_fill_list(size_t nbv, long int *val, t_list **l);
int			verif_val(int nbarg, char **value);
int			ft_index(size_t index_val, long int *tab, size_t size);
int			ft_issorted(size_t nbv, long int *values);
int			value_by_index(size_t i, t_list **l);
size_t		index_by_value(int value, t_list **l);

void		push(t_list **a, t_list **b, char c);
void		pushboth(t_list **dst, t_list **src);
void		swap(t_list **lst, char c);
void		swapboth(t_list **l1, t_list **l2);
void		rotate(t_list **lst, char c);
void		rotateboth(t_list **l1, t_list **l2);
void		reverse(t_list **lst, char c);
void		reverseboth(t_list **l1, t_list **l2);

#endif