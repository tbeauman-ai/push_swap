/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:55:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 21:24:01 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     seek_min_index(t_list *p)
{
    int     min;
    int     pindex;
    int     ret;

    min = *(int*)p->content;
    ret = 0;
    pindex = 0;
    while (p)
    {
        if (*(int*)p->content < min)
        {
            min = *(int*)p->content;
            ret = pindex;
        }
        p = p->next;
        pindex++;
    }
    return (ret);
}

int     sort(t_env *e)
{
    int     i_min;
    
    while (e->size_a)
    {
        i_min = seek_min_index(e->a);
        if (i_min > 1 + e->size_a / 2)
            while (i_min++ < e->size_a)
                rra(e);
        else
            while (i_min-- > 0)
                ra(e);
        pb(e);
    }
    while(e->size_b)
        pa(e);
    return (1);
}