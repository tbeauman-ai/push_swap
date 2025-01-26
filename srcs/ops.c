/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:58:29 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 17:04:20 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_env *e)
{
    push(&e->b, &e->a);
    e->size_b--;
    e->size_a++;
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_env *e)
{
    push(&e->a, &e->b);
    e->size_b++;
    e->size_a--;
    ft_putstr_fd("pb\n", 1);
}

void    sa(t_env *e)
{
    swap(&e->a);
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_env *e)
{
    swap(&e->b);
    ft_putstr_fd("sb\n", 1);
}

void    ra(t_env *e)
{
    rotate(&e->a);
    ft_putstr_fd("ra\n", 1);
}