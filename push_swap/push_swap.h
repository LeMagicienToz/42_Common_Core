/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:44:45 by muteza            #+#    #+#             */
/*   Updated: 2022/06/11 14:45:31 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_list{
	int				content;
	int				sortedindex;
	struct s_list	*next;
}t_list;

typedef struct s_exec{
	char	**tab_a;
	char	*str;
	char	**nb;
	int		*lowers_nb;
	int		index_topnb;
	int		k;
	int		i;
	int		v;
	int		min;
	t_list	*tmp_b;
	t_list	*tmp_a;
	t_list	*tmp;
	t_list	*a;
	t_list	*b;
}t_exec;

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);

int		index_min(t_exec *all);
int		is_trier(t_exec **all);
int		find_t_to_bot(t_exec *all);
int		find_b_to_top(t_exec *all);
int		check_if_good_pose(t_exec *all);
int		is_neg_samenb(t_exec *all);
int		is_good_index(t_exec *all);
int		rotate_b(t_exec *all);
int		rotate_a(t_exec *all);
int		push_a(t_exec *all);
int		is_int_max(t_exec *all);
int		ft_is_double(t_exec *all);
int		ft_isdigit(char c, t_exec *all);
int		is_nbr_double(t_exec *all);
int		ft_lstsize(t_list *lst);
int		swap_b(t_exec *all);
int		swap_a(t_exec *all);
int		ft_atoi(char *str);
int		push_b(t_exec *all);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parcing_args(char **argv, int argc, t_exec *all);
int		is_trillable(t_exec *all);
int		reverse_rotate_a(t_exec *all);
int		reverse_rotate_b(t_exec *all);
int		algo_third(t_exec *all);
int		parcing_algo(t_exec *all);
int		algo_five(t_exec *all);
int		search_push(t_exec *all);

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buf);

t_list	*ft_lstlast_m1(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	push_little_two(t_exec *all);
void	push_little(t_exec *all);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	algo_sorted(t_exec *all);
void	sorted_index(t_exec *all);
void	stock_lower_nb(t_exec *all);
void	assigne_sorted_index(t_exec *all);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ini_stack_b(t_exec *all);
void	sotck_tab_in_lst_string(char **argv, t_exec *all);
void	sotck_in_tab(char **str, t_exec *all);
void	make_a(t_exec *all, int i);
int		parcing_args(char **argv, int argc, t_exec *all);
#endif