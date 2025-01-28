/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:55:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/28 09:47:57 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void     sort(t_env *e)
{
    int     min;
    int     max;

    min = get_min(e->a);
    max = get_max(e->a);
    while (e->size_a > 3)
        if (*(int*)e->a->content == min || *(int*)e->a->content == max)        
            ra(e);
        else
            pb(e);
    small_sort_a(e);
    while (e->size_b)
    {
        pa(e);
        if (*(int*)e->a->content > *(int*)e->a->next->content)
            sa(e);
    }
    while (*(int*)e->a->content != min)
        ra(e);
}