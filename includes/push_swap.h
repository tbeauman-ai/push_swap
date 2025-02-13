/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:49:03 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/29 08:16:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "typedefs.h"
# define NUM_CHUNKS 50

void    check_args(int ac, const char **av);
void    ft_error(char *msg);
int     is_int(const char *str);

void    push(t_list **a, t_list **b);
void    swap(t_list **pile);
void    rotate(t_list **a);
void    reverse_rotate(t_list **a);

void    pa(t_env *e);
void    pb(t_env *e);
void    sa(t_env *e);
void    sb(t_env *e);
void    ra(t_env *e);
void    rb(t_env *e);
void    rra(t_env *e);
void    rrb(t_env *e);
void    rr(t_env *e);
void    rrr(t_env *e);

void    normalize(t_env *e);
int     is_reverse_sorted(t_list *a);
int     is_sorted(t_list *a);
void    small_sort_a(t_env *e);
void     sort(t_env *e);
t_list  *pile_dup(t_list *p);
t_list  *bubble_sort(t_list *p);
void    print_pile(t_list *a);
void    print_pile_bits(t_list *a);
void    print_pile_unsigned_bits(t_list *a);
int     get_max(t_list *p);
int     get_min(t_list *p);
int     seek_min_index(t_list *p);
int     seek_max_index(t_list *p);

void     sort(t_env *e);
void    little_sort(t_env *e);
void    radix_sort(t_env *e);
void    radix_sort_opti(t_env *e);
long	ft_atol(const char *str);

#endif