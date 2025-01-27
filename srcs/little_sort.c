/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:58:41 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 22:54:25 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_sort_a(t_env *e)
{
    int     max_index;

    if (e->size_a == 1)
        return ;
    if (e->size_a == 2)
    {
        if (!is_sorted(e->a))
            sa(e);
        return ;
    }
    if (e->size_a == 3)
    {
        max_index = seek_max_index(e->a);
        if (max_index == 0)
            ra(e);
        if (max_index == 1)
            rra(e);
        if (*(int*)e->a->content > *(int*)e->a->next->content)
            sa(e);
    }
}

void    small_sort_b(t_env *e)
{
    int     max_index;

    if (e->size_b == 1)
        return ;
    if (e->size_b == 2)
    {
        if (!is_sorted(e->b))
            sb(e);
        return ;
    }
    if (e->size_b == 3)
    {
        max_index = seek_max_index(e->b);
        if (max_index == 0)
            rb(e);
        if (max_index == 1)
            rrb(e);
        if (*(int*)e->b->content > *(int*)e->b->next->content)
            sb(e);
    }
}

void    little_sort(t_env *e)
{
    int     max;
    int     min;
    
    while (e->size_a > 3)
        pb(e);
    small_sort_a(e);
    small_sort_b(e);
    while (e->size_b)
    {
        max = get_max(e->a);
        min = get_min(e->a);
        if (*(int*)e->b->content < *(int*)e->a->content
        || (*(int*)e->b->content > max && *(int*)e->a->content == min))
            pa(e);
        ra(e);
    }
    min = get_min(e->a);
    while (*(int*)e->a->content != min)
        ra(e);
}