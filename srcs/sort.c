/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:55:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 21:30:08 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void     sort(t_env *e)
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
}