/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:11:23 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 16:13:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rb(t_env *e)
{
    rotate(&e->b);
    ft_putstr_fd("rb\n", 1);
}

void    rra(t_env *e)
{
    reverse_rotate(&e->a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_env *e)
{
    reverse_rotate(&e->b);
    ft_putstr_fd("rrb\n", 1);
}

void    rr(t_env *e)
{
    rotate(&e->a);
    rotate(&e->b);
    ft_putstr_fd("rr\n", 1);
}

void    rrr(t_env *e)
{
    reverse_rotate(&e->a);
    reverse_rotate(&e->b);
    ft_putstr_fd("rrr\n", 1);
}